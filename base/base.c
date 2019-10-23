#include "base.h"

VOID* BASE_Malloc(ULONG ulSize)
{
    return malloc(ulSize);
}

VOID BASE_Free(VOID *pPtr)
{
    free(pPtr);
    return;
}

VOID BASE_Memcpy(VOID *pDst, VOID *psrc, ULONG ulSize)
{
    memcpy(pDst, psrc, ulSize);
    return;
}

VOID BASE_Memset(VOID *pPtr, INT iValue, ULONG ulNum)
{
    memset(pPtr, iValue, ulNum);
}




