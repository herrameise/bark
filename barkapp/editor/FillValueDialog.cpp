#include "FillValueDialog.h"
using namespace bark::app;

#include <string>
using std::string;

#include <wx/msgdlg.h>



FillValueDialog::FillValueDialog(
    wxWindow*   parent,
    uint8_t*    byte) :
    FillValueDialogForm(parent),
    m_byte(byte)
{
    m_ButtonOK->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FillValueDialog::OnButtonOK, this);
    m_ButtonCancel->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &FillValueDialog::OnButtonCancel, this);
}


FillValueDialog::~FillValueDialog() {}


void FillValueDialog::OnButtonOK(
    wxCommandEvent& event)
{
    unsigned int byte;
    string str = m_TextCtrl->GetLineText(0).ToStdString();
    
    int rv = sscanf(str.c_str(), "%02X", &byte);

    if (rv != 1)
    {
        rv = sscanf(str.c_str(), "%02x", &byte);

        if (rv != 1)
        {
            wxMessageBox("Invalid hexadecimal byte value.", "Error", wxOK);
            return;
        }
    }

    *m_byte = (uint8_t)byte;
    EndModal(1);
}


void FillValueDialog::OnButtonCancel(
    wxCommandEvent& event)
{
    EndModal(0);
}