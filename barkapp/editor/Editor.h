#ifndef __BARK_APP___EDITOR_H__
#define __BARK_APP___EDITOR_H__

class wxWindow;

#include <bark/appstub/Blade.h>





namespace bark
{
    namespace core
    {
        class EditorCore;
    }

    namespace app
    {
        class Logger;
        class Manager;
        class Specimen;
        class EditorPanel;

        Blade* Editor_CreateBladeApp(
            bark::core::Blade* blade_core,
            LoggerBase*     logger,
            ManagerBase*    manager,
            SpecimenBase*   specimen);

        void Editor_DestroyBladeApp(
            Blade* blade);

        class Editor : public Blade
        {
        public:
            Editor(
                bark::core::EditorCore*     editor_core,
                Logger*                     logger,
                Manager*                    manager,
                Specimen*                   specimen);

            ~Editor() {}

            void Update(
                bark::core::BLADE_UPDATE    update,
                uint64_t                    val1,
                uint64_t                    val2,
                void*                       ptr) override;

            bool CreateUserInterface(
                void* parent) override;

            void DestroyUserInterface() override;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___EDITOR_H__