#ifndef _CMD_H_ 
#define _CMD_H_ 
#include "../base/base.h"

#define MAX_CMD_MODE_NUM 16
#define CMD_MODE_GLOBAL_STRING "global"

ULONG CMD_Init();

typedef enum eCmdModeType
{
	CMD_MODE_GLOBAL,
	CMD_MODE_MAX
}CMD_MODE_TYPE_EN;

INT g_iCmdMode;

typedef enum eCmdKeyType
{
	CMD_KEY_TYPE_KEY,
	CMD_KEY_TYPE_VALUE,
	CMD_KEY_TYPE_MAX
}CMD_KET_TYPE_EN;

typedef enum eCmdValueType
{
	CMD_VALUE_TYPE_NUM,
	CMD_VALUE_TYPE_STRING,
	CMD_VALUE_TYPE_MAX
}CMD_VALUE_TYPE_EN;

typedef struct stCmdTreeNode
{	
	CHAR  acCmdKey[100];
	ULONG ulCmdKeyId;
	UCHAR ucCmdKeyType;
	UCHAR ucCmdValueType;
	ULONG ulMinKeyValue;
	ULONG ulMaxKeyValue;
	ULONG ulStringLen;
	UCHAR ucCmdKeyLevel;
	struct stCmdTreeNode* pstChild;
	struct stCmdTreeNode* pstNext;
	struct stCmdTreeNode* pstParent;
}CMD_TREE_NODE_S;

CMD_TREE_NODE_S* g_apstCmdTreeHeads[MAX_CMD_MODE_NUM];

#endif
