#include "MaskValueDialog.h"
using namespace bark::app;

#include <string>
using std::string;

#include <wx/msgdlg.h>



MaskValueDialog::MaskValueDialog(
    wxWindow*   parent,
    uint8_t*    byte) :
    MaskValueDialogForm(parent),
    m_byte(byte)
{
    m_ButtonOK->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MaskValueDialog::OnButtonOK, this);
    m_ButtonCancel->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MaskValueDialog::OnButtonCancel, this);
}


MaskValueDialog::~MaskValueDialog() {}


void MaskValueDialog::OnButtonOK(
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


void MaskValueDialog::OnButtonCancel(
    wxCommandEvent& event)
{
    EndModal(0);
}