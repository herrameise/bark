#ifndef __BARK_CORE___PACKET_H__
#define __BARK_CORE___PACKET_H__

#include <cstdint>



namespace bark
{
    namespace core
    {
        class Packet
        {
        public:
            Packet(
                uint32_t        seconds,
                uint32_t        microseconds,
                unsigned int    length,
                uint8_t*        data);

            ~Packet();

            uint32_t GetSeconds() { return m_seconds; }
            uint32_t GetMicroseconds() { return m_microseconds; }
            unsigned int GetLength() { return m_length; }
            uint8_t* GetData() { return m_data; }

            void Clear();

            void SetData(
                unsigned int    length,
                uint8_t*        data);

        private:
            uint32_t            m_seconds;
            uint32_t            m_microseconds;

            unsigned int        m_length;

            uint8_t*            m_data;
        };

    } // namespace "core"
} // namespace "bark"



#endif // __BARK_CORE___PACKET_H__