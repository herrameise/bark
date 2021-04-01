#ifndef __BARK_APP___SPECIMEN_H__
#define __BARK_APP___SPECIMEN_H__

#include <bark/appstub/SpecimenBase.h>



namespace bark 
{
    namespace core
    {
        class Specimen;
    }

    namespace app
    {
        class Logger;
        class Manager;
        class MainWindow;

        class Specimen : public SpecimenBase
        {
        public:
            Specimen(
                bark::core::Specimen*   specimen_core,
                Logger*                 logger,
                Manager*                manager,
                MainWindow*             main_window);

            ~Specimen() {}

            bool LoadFile(
                const char*                 filename,
                bark::core::SPECIMEN_MODE   mode) override;

            void ClearSelection() override;

            void SetSelection(
                uint64_t    start_byte,
                uint8_t     start_bit,
                uint64_t    stop_byte,
                uint8_t     stop_bit) override;

            void SetSelection(
                unsigned int    packet,
                uint64_t        start_byte,
                uint8_t         start_bit,
                uint64_t        stop_byte,
                uint8_t         stop_bit) override;

        private:
            MainWindow* m_main_window;
        };

    } // namespace "app"
} // namespace "bark"



#endif  // __BARK_APP___SPECIMEN_H__