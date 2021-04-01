#ifndef __BARK_APP___MASK_VALUE_DIALOG_H__
#define __BARK_APP___MASK_VALUE_DIALOG_H__

#include "EditorForms.h"



namespace bark
{
    namespace app
    {
        class MaskValueDialog : public MaskValueDialogForm
        {
        public:
            MaskValueDialog(
                wxWindow*   parent,
                uint8_t*    byte);

            ~MaskValueDialog();

        private:
            void OnButtonOK(
                wxCommandEvent& event);

            void OnButtonCancel(
                wxCommandEvent& event);

            uint8_t* m_byte;
        };
    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___MASK_VALUE_DIALOG_H__