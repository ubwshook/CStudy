#ifndef _DATA_STRUCTURE_H_ 
#define _DATA_STRUCTURE_H_ 
#include "base.h"

#define MAX_STACK_SIZE 255

typedef struct stStack {
    INT iSize;
    INT* pBase;
    INT* pTop;
}STACK_S;


typedef struct stTree 
{
    VOID* pvData;
    struct stTree* pstChildNode;
    struct stTree* pstParentNode;
    struct stTree* pstNextNode;
}TREE_S;

typedef TREE_S* (*FIND_PARENT_NODE_FUNC)(TREE_S*, TREE_S*);

typedef BOOL (*COMPARE_NODE_FUNC)(VOID*, VOID*);

STACK_S* BASE_CreateStack(INT iStackSize);
VOID BASE_StackPush(STACK_S* pstStack, INT iVal);
INT BASE_StackPop(STACK_S* pstStack);
BOOL BASE_IsEmpty(STACK_S* pstStack);
VOID BASE_DestoryStack(STACK_S* pstStack);

#endif