#include "BladeEntriesListCtrl.h"
using namespace bark::app;

#include "Manager.h"



BladeEntriesListCtrl::BladeEntriesListCtrl(
    wxWindow *parent,
    wxWindowID id,
    const wxPoint& pos,
    const wxSize& size,
    long style) :
    wxListCtrl(parent, id, pos, size, style) {}


void BladeEntriesListCtrl::SetManager(
    Manager* manager)
{
    m_manager = manager;
}


wxString BladeEntriesListCtrl::OnGetItemText(
    long    item,
    long    column) const
{
    bark::core::BladeEntry* entry = m_manager->GetEntry((unsigned int)item);

    switch (column)
    {
    case BLADE_ENTRIES_COLUMN_NAME:
        return wxString(entry->metadata->name);
        break;

    case BLADE_ENTRIES_COLUMN_AUTHOR:
        return wxString(entry->metadata->author);
        break;

    case BLADE_ENTRIES_COLUMN_VERSION:
    {
        wxString text;
        text += wxString::Format("%u", entry->metadata->version_major);
        text += ".";
        text += wxString::Format("%u", entry->metadata->version_minor);
        text += ".";
        text += wxString::Format("%u", entry->metadata->version_patch);

        return text;
        break;
    }

    default:
        return wxString("");
    }
}