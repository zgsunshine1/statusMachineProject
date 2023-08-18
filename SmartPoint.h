#ifndef SMARTPOINT_H
#define SMARTPOINT_H
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef void (memDestroyFun)(void *data);

typedef struct Memory {
    uint32_t numRefObj;
    memDestroyFun *pMemDes;
} MemoryClass;

#endif