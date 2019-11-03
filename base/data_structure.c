#include "data_structure.h"
#include "error.h"


STACK_S* BASE_CreateStack(INT iStackSize)
{
    STACK_S* pstStack = NULL_PTR;
    if (iStackSize > iStackSize)
    {
        return ERROR_GENERAL_ERROR;
    }

    pstStack = (STACK_S*)BASE_Malloc(sizeof(STACK_S));
    if (pstStack == NULL_PTR)
    {
        return ERROR_MALLOC_FAIL;
    }

    pstStack->pBase = (INT*)BASE_Malloc(sizeof(INT) * iStackSize);
    pstStack->iSize = iStackSize;
    pstStack->pTop = pstStack->pBase;
    return pstStack;
}

VOID BASE_StackPush(STACK_S* pstStack, INT iVal)
{
    if (pstStack->pTop - pstStack->pBase == pstStack->iSize)
    {
        return ERROR_STACK_FULL;
    }

    *(pstStack->pTop++) = iVal;

    return;
}

INT BASE_StackPop(STACK_S* pstStack)
{
    if (pstStack->pTop == pstStack->pBase)
    {
        return;
    }
    return *(pstStack->pTop--);
}

BOOL BASE_IsEmpty(STACK_S* pstStack)
{
    return (pstStack->pTop == pstStack->pBase);
}

VOID BASE_DestoryStack(STACK_S* pstStack)
{
    BASE_Free(pstStack->pBase);
    BASE_Free(pstStack);

    return;
}


TREE_S* BASE_CreateTree(VOID *pvData) 
{
    TREE_S* pstTreeRoot = NULL_PTR;
    pstTreeRoot = (TREE_S*)BASE_Malloc(sizeof(TREE_S));
    if (NULL_PTR == pstTreeRoot)
    {
        return ERROR_MALLOC_FAIL;
    }

    pstTreeRoot->pvData = pvData;

    return pstTreeRoot;
}

ULONG BASE_AddTreeNode(TREE_S* pstTreeRoot, TREE_S* pstTreeNode, FIND_PARENT_NODE_FUNC pfFindParentNode)
{
    TREE_S* pstParentNode = NULL_PTR;
    TREE_S* pstTmpNode = NULL_PTR;

    if (NULL_PTR == pstTreeRoot || NULL_PTR == pstTreeNode)
    {
        return ERROR_GENERAL_ERROR;
    }

    pstParentNode = (*pfFindParentNode)(pstTreeRoot, pstTreeNode);
    if (pstParentNode == NULL_PTR) 
    {
        return ERROR_TREE_NO_PARENT;
    }

    if (NULL_PTR == pstParentNode->pstChildNode)
    {
        pstParentNode->pstChildNode = pstTreeNode;
        pstTreeNode->pstParentNode = pstParentNode->pstChildNode;
        return OK;
    }

    pstTmpNode = pstParentNode->pstChildNode;
    while (TRUE) 
    {
        if (pstTmpNode->pstNextNode == NULL_PTR)
        {
            pstTmpNode->pstNextNode = pstTreeNode;
            pstTreeNode->pstParentNode = pstTmpNode;
            return OK;
        }

        pstTmpNode = pstTmpNode->pstNextNode;
    }
}

TREE_S* BASE_FindTreeNode(TREE_S* pstTreeRoot, VOID* pvData, COMPARE_NODE_FUNC pfFindNode)
{
    TREE_S* pstTmpNode = NULL_PTR;
    TREE_S* pstTmpChildNode = NULL_PTR;

    pstTmpNode = pstTreeRoot;
    pstTmpChildNode = pstTreeRoot->pstChildNode;
    while (!pfFindNode(pvData, pstTmpNode->pvData))
    {
        if (NULL_PTR == pstTmpNode->pstNextNode);
    }
}