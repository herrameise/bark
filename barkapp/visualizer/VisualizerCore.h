#ifndef __BARK_CORE___VISUALIZER_CORE_H__
#define __BARK_CORE___VISUALIZER_CORE_H__

#include <bark/Blade.h>



namespace bark
{
    namespace core
    {
        class Logger;
        class Manager;
        class Specimen;

        BladeMetadata* Visualizer_GetMetadata();

        Blade* Visualizer_CreateBladeCore(
            Logger*     logger,
            Manager*    manager,
            Specimen*   specimen);

        void Visualizer_DestroyBladeCore(
            Blade* blade);

        class VisualizerCore : public Blade
        {
        public:
            VisualizerCore(
                Logger*     logger,
                Manager*    manager,
                Specimen*   specimen);

            ~VisualizerCore() {}

            void UpdateCore(
                BLADE_UPDATE    update,
                uint64_t        val1,
                uint64_t        val2,
                void*           ptr) override;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___VISUALIZER_CORE_H__