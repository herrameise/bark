#include "MainPanel.h"
using namespace blade::blade_template::app;



MainPanel::MainPanel(
    wxWindow* parent) :
    MainPanelForm(parent) {}


MainPanel::~MainPanel() {}


void MainPanel::WriteMessage(
    wxString string)
{
    m_RichTextCtrl->WriteText(string + "\n");
}