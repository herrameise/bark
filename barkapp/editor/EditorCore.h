#ifndef __BARK_CORE___EDITOR_CORE_H__
#define __BARK_CORE___EDITOR_CORE_H__

#include <bark/Blade.h>



namespace bark
{
    namespace core
    {
        class Logger;
        class Manager;
        class Specimen;

        BladeMetadata* Editor_GetMetadata();

        Blade* Editor_CreateBladeCore(
            Logger*     logger,
            Manager*    manager,
            Specimen*   specimen);

        void Editor_DestroyBladeCore(
            Blade* blade);

        class EditorCore : public Blade
        {
        public:
            EditorCore(
                Logger*     logger,
                Manager*    manager,
                Specimen*   specimen);

            ~EditorCore() {}

            void UpdateCore(
                BLADE_UPDATE    update,
                uint64_t        val1,
                uint64_t        val2,
                void*           ptr) override;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___EDITOR_CORE_H__