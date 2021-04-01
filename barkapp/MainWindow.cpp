#include "MainWindow.h"
using namespace bark::app;

#include <wx/msgdlg.h>
#include <wx/filedlg.h>

#include <bark/Bark.h>
#include <bark/Manager.h>
#include "editor/Editor.h"
#include "Logger.h"
#include "Manager.h"
#include "Specimen.h"
#include "StatusBar.h"
#include "Version.h"



MainWindow::MainWindow():
    MainWindowForm(nullptr)
{
    BindEvents();

    m_StatusBar->SetFieldsCount(STATUS_BAR_FIELDS);

    // create BARK core
    m_bark_core = new bark::core::Bark();
    m_bark_core->Initialize(); // not sure how to check this gracefully

    // create logger
    m_logger = new Logger(m_bark_core->GetLogger());
    m_logger->CreatePanel(this);
    wxWindow* logger_panel = m_logger->GetPanel();
    m_mgr.AddPane(logger_panel, wxCENTER, "Logger");
    wxAuiPaneInfo& pane = m_mgr.GetPane(logger_panel);
    pane.Dockable(true);
    pane.Floatable(true);
    pane.CaptionVisible(true);
    pane.MaximizeButton(true);
    pane.MinimizeButton(true);
    pane.Bottom();
    m_mgr.Update();

    // create manager and specimen
    m_manager = new Manager(m_bark_core->GetManager(), m_logger, this, &m_mgr);
    m_specimen = new Specimen(m_bark_core->GetSpecimen(), m_logger, m_manager, this);
    m_manager->SetSpecimen(m_specimen);

    m_manager->LoadInternalBlades();

    m_manager->SetBladesDirectory(".");
    m_manager->RefreshEntries();

    m_specimen->Clear();
}


MainWindow::~MainWindow()
{
    m_manager->CloseAllBlades();

    delete m_specimen;
    delete m_manager;
    delete m_logger;
    delete m_bark_core;
}


void MainWindow::UpdateTitle(
    wxString filename)
{
    wxString text = wxString::Format(
        "BARK v%u.%u.%u -- ",
        BARK_APP_VERSION_MAJOR,
        BARK_APP_VERSION_MINOR,
        BARK_APP_VERSION_PATCH);

    if (filename == wxString("")) text += wxString("(no Specimen loaded)");
    else text += filename;

    SetTitle(text);
}


void MainWindow::UpdateStatusBarStatus(
    wxString status)
{
    wxString text = "Status: ";
    text += status;

    m_StatusBar->SetStatusText(text, STATUS_BAR_FIELD_STATUS);
}


void MainWindow::UpdateStatusBarSelectionRange(
    uint32_t start,
    uint32_t stop)
{
    uint32_t low = ((start <= stop) ? start : stop);
    uint32_t high = ((start >= stop) ? start : stop);
    uint32_t range = (high - low) + 1;

    wxString text = "Selection: ";
    if (start >= 0 && stop >= 0)
    {
        text << low;
        text << " to ";
        text << high;
        text << " (";
        text << range;
        text << " bytes)";
    }

    m_StatusBar->SetStatusText(text, STATUS_BAR_FIELD_SELECTION);
}


void MainWindow::OnMenuFileLoadSpecimen(
    wxCommandEvent& event)
{
    wxFileDialog dlg(this, "Load Specimen", "", "", "All Files (*)|*");
    int rv = dlg.ShowModal();

    if (rv == wxCANCEL) return;

    wxString filename = dlg.GetPath();
    if (filename == wxString("")) return;

    m_specimen->LoadFile(filename.ToStdString().c_str(), bark::core::SPECIMEN_MODE_BLOB);
}


void MainWindow::OnMenuFileExit(
    wxCommandEvent& event)
{
    Close();
}


void MainWindow::OnMenuBladesDeploy(
    wxCommandEvent& event)
{
    m_manager->LaunchDeployBladeDialog();
}


void MainWindow::OnMenuHelpAbout(
    wxCommandEvent& event)
{
    wxString text;
    text.Append("BARK: the Binary Army Knife\n");
    text.Append("Dave Twitchell - DZ Labs\n\n");

    text.Append(wxString::Format(
        "Core Version %u.%u.%u\n",
        m_bark_core->GetVersionMajor(),
        m_bark_core->GetVersionMinor(),
        m_bark_core->GetVersionPatch()));

    text.Append(wxString::Format(
        "Application Version %u.%u.%u\n",
        BARK_APP_VERSION_MAJOR,
        BARK_APP_VERSION_MINOR,
        BARK_APP_VERSION_PATCH));

    text.Append(wxString::Format(
        "Built on %s at %s\n\n",
        BARK_APP_BUILD_DATE,
        BARK_APP_BUILD_TIME));

    wxMessageBox(text, "About");
}


void MainWindow::BindEvents()
{
    Bind(wxEVT_CLOSE_WINDOW, &MainWindow::OnClose, this);
}


void MainWindow::OnClose(
    wxCloseEvent& event)
{
    int rv = wxMessageBox("Are you sure you want to exit BARK?", "Exit", wxYES_NO);
    if (rv == wxNO)
    {
        event.Veto();
        return;
    }

    event.Skip();
}