#include "Debug.h"

#include <cstdio>



void bark::core::PrintBytes(
    uint8_t*        bytes,
    unsigned int    size,
    unsigned int    bytes_per_line)
{
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%02X ", bytes[i]);
        if ((i + 1) % bytes_per_line == 0) printf("\n");
    }

    printf("\n");
}