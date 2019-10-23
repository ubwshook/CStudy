#ifndef _CMD_H_ 
#define _CMD_H_ 
#include "../base/base.h"
#include "../base/error.h"

#define MAX_CMD_MODE_NUM 16
#define CMD_MODE
#define CMD_MODE_GLOBAL_STRING "global"
#define MAX_CMD_KEY_LEN 100
#define MAX_CMD_LEN 255

typedef enum eCmdModeType
{
	CMD_MODE_GLOBAL,
	CMD_MODE_BUTT
}CMD_MODE_TYPE_EN;

INT g_iCmdMode;
CHAR g_acCmdModeStringList[MAX_CMD_MODE_NUM][MAX_CMD_KEY_LEN];

typedef enum eCmdKeyType
{
	CMD_KEY_TYPE_KEY,
	CMD_KEY_TYPE_VALUE,
	CMD_KEY_TYPE_BUTT
}CMD_KET_TYPE_EN;

typedef enum eCmdValueType
{
	CMD_VALUE_TYPE_NUM,
	CMD_VALUE_TYPE_STRING,
	CMD_VALUE_TYPE_BUTT
}CMD_VALUE_TYPE_EN;

typedef enum eCmdKeyRelType
{
	CMD_KEY_REL_TYPE_CHOOSE_ONE,
	CMD_KEY_REL_TYPE_CHOOSE_ONE_MUST,
	CMD_KEY_REL_TYPE_CHOOSE_MORE,
	CMD_KEY_REL_TYPE_CHOOSE_MORE_MUST,
	CMD_KEY_REL_TYPE_BUTT
}CMD_KEY_REL_TYPE_EN;

typedef enum eCmdKey
{
	GLOBAL_DISPLAY = 0,   /* display */
	GLOBAL_VERSION = 1,   /* version */
	GLOBAL_TIME = 2,      /* time    */
	CMD_KEY_BUTT
}CMD_KEY_EN;

typedef struct stCmdTreeNode
{	
	CHAR  acCmdKey[MAX_CMD_KEY_LEN];
	ULONG ulCmdKeyId;
	UCHAR ucCmdKeyType;
	UCHAR ucCmdValueType;
	ULONG ulMinKeyValue;
	ULONG ulMaxKeyValue;
	ULONG ulStringLen;
	UCHAR ucCmdKeyLevel;
	UCHAR ucCmdKeyRelType;
	struct stCmdTreeNode* pstChildListHead;
	struct stCmdTreeNode* pstNext;
	struct stCmdTreeNode* pstParent;
}CMD_TREE_NODE_S;

CMD_TREE_NODE_S* g_apstCmdTreeHeads[MAX_CMD_MODE_NUM];
CMD_TREE_NODE_S* g_pstCmdKeyList;

ULONG CMD_Init();
ULONG CMD_KeyInit();
ULONG CMD_CmdEntry();

#endif
