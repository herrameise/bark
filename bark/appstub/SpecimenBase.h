#ifndef __BARK_APP___SPECIMEN_BASE_H__
#define __BARK_APP___SPECIMEN_BASE_H__

#include <cstdint>

#include "../Export.h"
#include "../Specimen.h"



namespace bark
{
    namespace core
    {
        class Specimen;
    }

    namespace app
    {
        class LoggerBase;
        class ManagerBase;

        class BARK_EXPORT SpecimenBase
        {
        public:
            SpecimenBase(
                bark::core::Specimen*   specimen_core,
                LoggerBase*             logger,
                ManagerBase*            manager);

            virtual ~SpecimenBase() {}

            bool Exists();

            bark::core::SPECIMEN_MODE GetMode();

            const char* GetName();

            void SetName(
                const char* name);

            void Clear();

            virtual bool LoadFile(
                const char*                 filename,
                bark::core::SPECIMEN_MODE   mode);

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

            bool SelectionExists();

            unsigned int GetSelectionPacket();

            uint64_t GetSelectionStartByte();

            uint8_t GetSelectionStartBit();

            uint64_t GetSelectionStopByte();

            uint8_t GetSelectionStopBit();

            virtual void ClearSelection();

            virtual void SetSelection(
                uint64_t    start_byte,
                uint8_t     start_bit,
                uint64_t    stop_byte,
                uint8_t     stop_bit);

            virtual void SetSelection(
                unsigned int    packet,
                uint64_t        start_byte,
                uint8_t         start_bit,
                uint64_t        stop_byte,
                uint8_t         stop_bit);

        protected:
            bark::core::Specimen*   m_specimen_core;
            LoggerBase*             m_logger;
            ManagerBase*            m_manager;
        };

    } // namespace "app"
} // namespace "bark"



#endif // __BARK_APP___SPECIMEN_BASE_H__