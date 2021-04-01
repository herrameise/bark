#ifndef __BARK_APP___FILL_VALUE_DIALOG_H__
#define __BARK_APP___FILL_VALUE_DIALOG_H__

#include "EditorForms.h"



namespace bark
{
    namespace app
    {
        class FillValueDialog : public FillValueDialogForm
        {
        public:
            FillValueDialog(
                wxWindow*   parent,
                uint8_t*    byte);

            ~FillValueDialog();

        private:
            void OnButtonOK(
                wxCommandEvent& event);

            void OnButtonCancel(
                wxCommandEvent& event);

            uint8_t* m_byte;
        };
    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___FILL_VALUE_DIALOG_H__