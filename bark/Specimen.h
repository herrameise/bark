#ifndef __BARK_CORE___SPECIMEN_H__
#define __BARK_CORE___SPECIMEN_H__

#include "Export.h"

#include <cstdint>



namespace bark
{
    namespace app
    {
        class SpecimenBase;
    }

    namespace core
    {
        class SpecimenOpaque;
        class Logger;
        class Manager;

        typedef enum SPECIMEN_ENCODING
        {
            SPECIMEN_ENCODING_PACKED = 0,
            SPECIMEN_ENCODING_UNPACKED = 1,
        } SPECIMEN_ENCODING;

        typedef enum SPECIMEN_MODE
        {
            SPECIMEN_MODE_BLOB = 0,
            SPECIMEN_MODE_PACKET = 1,
        } SPECIMEN_MODE;

        class BARK_EXPORT Specimen
        {
        public:
            Specimen(
                Logger*     logger,
                Manager*    manager);

            ~Specimen();

            bark::app::SpecimenBase* GetAppComponent() { return m_app_component; }

            void SetAppComponent(
                bark::app::SpecimenBase* app_component) { m_app_component = app_component; }

            bool Exists() { return m_exists; }

            SPECIMEN_MODE GetMode() { return m_mode; }

            const char* GetName();

            void SetName(
                const char* name);

            void Clear();

            // REDIRECTOR
            bool LoadFile(
                const char*         filename,
                SPECIMEN_MODE       mode);

            bool LoadFileCore(
                const char*         filename,
                SPECIMEN_MODE       mode);

            bool ParsePcap(
                uint64_t    length,
                uint8_t*    bytes);

            uint8_t* GetRawData();

            uint64_t GetSize();

            unsigned int GetPacketCount();

            bool GetBytes(
                uint64_t    offset,
                uint64_t    size,
                uint8_t*    buffer);

            bool FillBytes(
                uint64_t    offset,
                uint64_t    size,
                uint8_t     value);

            bool ReplaceBytes(
                uint64_t    offset,
                uint64_t    size,
                uint8_t*    bytes);

            bool InsertBytes(
                uint64_t    offset,
                uint64_t    size,
                uint8_t*    bytes);

            bool DeleteBytes(
                uint64_t    offset,
                uint64_t    size);

            bool SelectionExists() { return m_selection_exists; }

            unsigned int GetSelectionPacket() { return m_selection_packet; }

            uint64_t GetSelectionStartByte() { return m_selection_start_byte; }

            uint8_t GetSelectionStartBit() { return m_selection_start_bit; }

            uint64_t GetSelectionStopByte() { return m_selection_stop_byte; }

            uint8_t GetSelectionStopBit() { return m_selection_stop_bit; }

            // REDIRECTOR
            void ClearSelection();

            void ClearSelectionCore();

            // REDIRECTOR
            void SetSelection(
                uint64_t    start_byte,
                uint8_t     start_bit,
                uint64_t    stop_byte,
                uint8_t     stop_bit);

            // REDIRECTOR
            void SetSelection(
                unsigned int    packet,
                uint64_t        start_byte,
                uint8_t         start_bit,
                uint64_t        stop_byte,
                uint8_t         stop_bit);

            void SetSelectionCore(
                uint64_t    start_byte,
                uint8_t     start_bit,
                uint64_t    stop_byte,
                uint8_t     stop_bit);

            void SetSelectionCore(
                unsigned int    packet,
                uint64_t        start_byte,
                uint8_t         start_bit,
                uint64_t        stop_byte,
                uint8_t         stop_bit);

        private:
            SpecimenOpaque*             m_opaque;
            bark::app::SpecimenBase*    m_app_component;
            Logger*                     m_logger;
            Manager*                    m_manager;

            bool                        m_exists;

            SPECIMEN_MODE               m_mode;

            bool                        m_selection_exists;
            unsigned int                m_selection_packet;
            uint64_t                    m_selection_start_byte;
            uint8_t                     m_selection_start_bit;
            uint64_t                    m_selection_stop_byte;
            uint8_t                     m_selection_stop_bit;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___SPECIMEN_H__