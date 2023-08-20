#ifndef SMARTPOINT_H
#define SMARTPOINT_H
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
typedef void (memDestroyFun)(void *data);
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//struct argStruct{
//size_t size;
//memDestroyFun *pMemDes;
//}argStruct;
typedef struct Memory {
    uint32_t numRefObj;
    memDestroyFun *pMemDes;
} MemoryClass;

#endif