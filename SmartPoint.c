#include "SmartPoint.h"
void *memAlloc(const size_t size, memDestroyFun *pMemDes)
{
    MemoryClass *pMem;
    pMem = (MemoryClass *) malloc(sizeof(*pMem) + size);
    if (!pMem)
	{
        return NULL;
	}
    pMem->numRefObj = 1;
    pMem->pMemDes   = pMemDes;
    return (void *)(pMem + 1);
}

void *memRef(void *data)
{
    MemoryClass *pMem;
    if (!data)
	{
      return NULL;
    }
    pMem = ((MemoryClass*)data) - 1;
    ++pMem->numRefObj;
    return data;
}


void *memDeref(void *data)
{
    MemoryClass *pMem;
    if (!data)
	{
	   return NULL;
	}
    pMem = ((MemoryClass*)data) - 1;

    if (--pMem->numRefObj > 0)
	{
        return NULL;
	}
    if (pMem->pMemDes)
	{
        pMem->pMemDes(data);
	}
    if (pMem->numRefObj > 0)
        return NULL;
    free(pMem);
    return NULL;
}
