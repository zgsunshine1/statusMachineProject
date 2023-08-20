#include "inc/SmartPoint.h"

// void funDestroy (void * pMem)
// {
//    (MemoryClass *)pMen-> numRefObj = 0;
//    free(pMem);
//    pMem = NULL;
// }

void *memAlloc(const size_t size, memDestroyFun *pMemDes)
{
    //pthread_mutex_lock(mutex);
    MemoryClass *pMem;
    pMem = (MemoryClass *) malloc(sizeof(*pMem) + size);
    if (!pMem)
	{
        return NULL;
	}
    pMem->numRefObj = 1;
    pMem->pMemDes   = pMemDes;
    //pthread_mutex_unlock(mutex);
    return (void *)(pMem);
}

void *memRef(void *data)
{
    if (!data)
	{
      return NULL;
    }
    MemoryClass *pMem;
    pMem = ((MemoryClass*)data);
    ++pMem->numRefObj;
    return data;
}


void *memDeref(void *data)
{
    if (!data)
	{
	   return NULL;
	}
    MemoryClass *pMem = ((MemoryClass*)data);

    if ((--pMem->numRefObj) == 0)
	{
        pMem->pMemDes= ((MemoryClass*)data)->pMemDes;
        free(pMem);
        pMem = NULL;
        data = NULL;
        return data;
	}
    return data;
}
