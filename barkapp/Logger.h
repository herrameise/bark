#ifndef __BARK_APP___LOGGER_H__
#define __BARK_APP___LOGGER_H__

class wxWindow;

#include <bark/appstub/LoggerBase.h>



namespace bark
{
    namespace core
    {
        class Logger;
    }

    namespace app
    {
        class LoggerPanel;

        class Logger : public LoggerBase
        {
        public:
            Logger(
                bark::core::Logger* logger_core);

            ~Logger();

            void Log(
                void*                       source,
                bark::core::LOGGER_LEVEL    level,
                const char*                 message) override;

            bool CreatePanel(
                wxWindow* parent);

            wxWindow* GetPanel();

            void DestroyPanel();

        private:
            LoggerPanel* m_panel;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___LOGGER_H__