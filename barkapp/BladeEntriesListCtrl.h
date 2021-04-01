#ifndef __BARK_APP___BLADE_ENTRIES_LIST_CTRL_H__
#define __BARK_APP___BLADE_ENTRIES_LIST_CTRL_H__

#include <wx/listctrl.h>



#define BLADE_ENTRIES_COLUMN_COUNT      3   // count

#define BLADE_ENTRIES_COLUMN_NAME       0   // index
#define BLADE_ENTRIES_COLUMN_AUTHOR     1   // index
#define BLADE_ENTRIES_COLUMN_VERSION    2   // index



namespace bark
{
    namespace app
    {
        class Manager;

        class BladeEntriesListCtrl : public wxListCtrl
        {
        public:
            BladeEntriesListCtrl(
                wxWindow *parent,
                wxWindowID id,
                const wxPoint& pos,
                const wxSize& size,
                long style);

            ~BladeEntriesListCtrl() {}

            void SetManager(
                Manager* manager);

        private:
            Manager* m_manager;

            wxString OnGetItemText(
                long    item,
                long    column) const override;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___BLADE_ENTRIES_LIST_CTRL_H__