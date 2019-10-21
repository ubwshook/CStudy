/* 数据类型定义 */
#ifndef _BASE_H_ 
#define _BASE_H_ 
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define TRUE  1
#define FALSE 0
#define OK    0
#define NULL_PTR NULL

typedef void VOID;
typedef short int SHORT;
typedef int INT;
typedef long int LONG;
typedef char CHAR;

typedef unsigned int UINT;
typedef unsigned short int USHORT;
typedef unsigned long int ULONG;
typedef unsigned char UCHAR;
typedef INT BOOL;

VOID* BASE_Malloc(ULONG ulSize);
VOID BASE_Free(VOID* pPtr);
VOID BASE_Memcpy(VOID* pDst, VOID* psrc, ULONG ulSize);
VOID BASE_Memset(VOID* pPtr, INT iValue, ULONG ulNum);

#endif
