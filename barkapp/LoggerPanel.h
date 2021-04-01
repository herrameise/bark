#ifndef __BARK_APP___LOGGER_PANEL_H__
#define __BARK_APP___LOGGER_PANEL_H__

class wxWindow;

#include <bark/Logger.h>
#include "LoggerForms.h"



namespace bark
{
    namespace app
    {
        class LoggerPanel : public LoggerPanelForm
        {
        public:
            LoggerPanel(
                wxWindow* parent);

            ~LoggerPanel();

            void Log(
                bark::core::LOGGER_LEVEL    level,
                const char*                 source,
                const char*                 message);
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___LOGGER_PANEL_H__