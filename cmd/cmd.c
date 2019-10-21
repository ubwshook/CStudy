#include "cmd.h"

VOID CMD_SetDeafultMode() 
{
	g_iCmdMode = CMD_MODE_GLOBAL;
	return;
}

VOID CMD_InitTreeRoot(CMD_TREE_NODE_S* pstTreeHead)
{
	BASE_Memset(pstTreeHead, 0, sizeof(CMD_TREE_NODE_S));
	return;
}

ULONG CMD_InitCmdSingleTree(CMD_MODE_TYPE_EN eCmdMode, CMD_TREE_NODE_S* pstTreeHead)
{
	

	return OK;
}

ULONG CMD_IintCmdTree()
{
	USHORT usLoop = 0;
	for (usLoop = 0; usLoop <= CMD_MODE_MAX; usLoop++)
	{
		g_apstCmdTreeHeads[usLoop] = (CMD_TREE_NODE_S*)BASE_Malloc(sizeof(CMD_TREE_NODE_S));
		CMD_InitCmdSingleTree(usLoop, g_apstCmdTreeHeads[usLoop]);
	}

	return OK;
}

ULONG CMD_Init()
{
	printf("Begin init CmdTree! \n");
	CMD_SetDeafultMode();
	return OK;
}