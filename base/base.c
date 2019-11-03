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

ULONG BASE_StrLen(CHAR* pcString)
{
    return strlen(pcString);
}

CHAR* BASE_StrNCpy(CHAR* pcDstStr, CHAR* pcSrcStr, ULONG ulSize)
{
    return strncpy(pcDstStr, pcSrcStr, ulSize);
}

INT BASR_StrCmp(CHAR* pcStr1, CHAR* pcStr2)
{
    return strcmp(pcStr1, pcStr2);
}


