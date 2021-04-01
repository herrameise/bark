#ifndef __BARK_APP___VISUALIZER_H__
#define __BARK_APP___VISUALIZER_H__

class wxWindow;

#include <bark/appstub/Blade.h>





namespace bark
{
    namespace core
    {
        class VisualizerCore;
    }

    namespace app
    {
        class Logger;
        class Manager;
        class Specimen;
        class VisualizerPanel;

        Blade* Visualizer_CreateBladeApp(
            bark::core::Blade* blade_core,
            LoggerBase*     logger,
            ManagerBase*    manager,
            SpecimenBase*   specimen);

        void Visualizer_DestroyBladeApp(
            Blade* blade);

        class Visualizer : public Blade
        {
        public:
            Visualizer(
                bark::core::VisualizerCore*     visualizer_core,
                Logger*                         logger,
                Manager*                        manager,
                Specimen*                       specimen);

            ~Visualizer() {}

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



#endif // __BARK_APP___VISUALIZER_H__