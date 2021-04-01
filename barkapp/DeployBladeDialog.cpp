#include "DeployBladeDialog.h"
using namespace bark::app;

#include <wx/msgdlg.h>

#include "BladeEntriesListCtrl.h"
#include "Manager.h"



DeployBladeDialog::DeployBladeDialog(
    Manager* manager) :
    DeployBladeDialogForm(nullptr),
    m_manager(manager)
{
    m_BladeEntriesListCtrl->SetManager(m_manager);
    m_BladeEntriesListCtrl->AppendColumn("Name");
    m_BladeEntriesListCtrl->AppendColumn("Author");
    m_BladeEntriesListCtrl->AppendColumn("Version");

    RefreshBladeEntriesListCtrl();
}


BladeEntriesListCtrl* DeployBladeDialog::GetBladeEntriesListCtrl()
{
    return m_BladeEntriesListCtrl;
}


void DeployBladeDialog::RefreshBladeEntriesListCtrl()
{
    m_BladeEntriesListCtrl->SetItemCount(m_manager->GetEntryCount());
    m_BladeEntriesListCtrl->RefreshItems(0, m_BladeEntriesListCtrl->GetItemCount() - 1);

    // adjust column widths
    m_BladeEntriesListCtrl->SetColumnWidth(BLADE_ENTRIES_COLUMN_NAME, wxLIST_AUTOSIZE);
    m_BladeEntriesListCtrl->SetColumnWidth(
        BLADE_ENTRIES_COLUMN_NAME,
        m_BladeEntriesListCtrl->GetColumnWidth(BLADE_ENTRIES_COLUMN_NAME) + 10);

    m_BladeEntriesListCtrl->SetColumnWidth(BLADE_ENTRIES_COLUMN_AUTHOR, wxLIST_AUTOSIZE);
    m_BladeEntriesListCtrl->SetColumnWidth(
        BLADE_ENTRIES_COLUMN_AUTHOR,
        m_BladeEntriesListCtrl->GetColumnWidth(BLADE_ENTRIES_COLUMN_AUTHOR) + 10);

    m_BladeEntriesListCtrl->SetColumnWidth(BLADE_ENTRIES_COLUMN_VERSION, wxLIST_AUTOSIZE_USEHEADER);
    m_BladeEntriesListCtrl->SetColumnWidth(
        BLADE_ENTRIES_COLUMN_VERSION,
        m_BladeEntriesListCtrl->GetColumnWidth(BLADE_ENTRIES_COLUMN_VERSION) + 10);
}


void DeployBladeDialog::OnButtonDeploy(wxCommandEvent& event)
{
    int count = m_BladeEntriesListCtrl->GetSelectedItemCount();
    if (count == 0) return;

    long item = -1;
    while (true)
    {
        item = m_BladeEntriesListCtrl->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
        if (item == -1) break;

        bool rv = m_manager->DeployBlade(m_manager->GetEntry(item));
        if (rv == false)
        {
            wxMessageBox("Unable to deploy the selected blade.", "Error!", wxOK | wxICON_ERROR);
            return;
        }
        return;
    }

    wxMessageBox("No blade selected.", "Error!", wxOK | wxICON_ERROR);
}


void DeployBladeDialog::OnButtonClose(wxCommandEvent& event)
{
    Destroy();
}