#include "cmd.h"

VOID CMD_SingleRegister(CHAR* pcCmdKey, 
                        ULONG ulCmdKeyId, 
                        UCHAR ucCmdKeyType,
                        UCHAR ucCmdValueType,
                        ULONG ulMinKeyValue,
                        ULONG ulMaxKeyValue,
                        ULONG ulStringLen
                        )
{
    CMD_TREE_NODE_S* pstCurrentCmdKey = g_pstCmdKeyList + ulCmdKeyId;
    BASE_Memcpy(pstCurrentCmdKey->acCmdKey, pcCmdKey, strlen(pcCmdKey) + 1);
    pstCurrentCmdKey->ulCmdKeyId = ulCmdKeyId;
    pstCurrentCmdKey->ucCmdKeyType = ucCmdKeyType;
    pstCurrentCmdKey->ucCmdValueType = ucCmdValueType;
    pstCurrentCmdKey->ulMinKeyValue = ulMinKeyValue;
    pstCurrentCmdKey->ulMaxKeyValue = ulMaxKeyValue;
    pstCurrentCmdKey->ulMaxKeyValue = ulMaxKeyValue;
    pstCurrentCmdKey->ulStringLen = ulStringLen;

    return;
}

VOID CMD_DisplayCmdKey()
{
    ULONG ulLoop;
    CMD_TREE_NODE_S* pstCurrentCmdKey;
    
    for (ulLoop = 0; ulLoop < CMD_KEY_BUTT; ulLoop++)
    {
        pstCurrentCmdKey = g_pstCmdKeyList + ulLoop;
        printf("No%d: %s \n", pstCurrentCmdKey->ulCmdKeyId, pstCurrentCmdKey->acCmdKey);
    }

    return;
}

ULONG CMD_KeyInit() 
{
    ULONG ulRet = OK;
    ULONG ulAllCmdKeyLen = sizeof(CMD_TREE_NODE_S) * CMD_KEY_BUTT;
    g_pstCmdKeyList = (CMD_TREE_NODE_S*)BASE_Malloc(ulAllCmdKeyLen);
    if (g_pstCmdKeyList == NULL_PTR)
    {
        return ERROR_MALLOC_FAIL;
    }

    BASE_Memset(g_pstCmdKeyList, 0, ulAllCmdKeyLen);

    /* $1 global:display */
    CMD_SingleRegister("display", GLOBAL_DISPLAY, CMD_KEY_TYPE_KEY, CMD_NULL, CMD_NULL, CMD_NULL, CMD_NULL);

    /* $2 global:version */
    CMD_SingleRegister("version", GLOBAL_VERSION, CMD_KEY_TYPE_KEY, CMD_NULL, CMD_NULL, CMD_NULL, CMD_NULL);

    /* $3 global:time */
    CMD_SingleRegister("time", GLOBAL_TIME, CMD_KEY_TYPE_KEY, CMD_NULL, CMD_NULL, CMD_NULL, CMD_NULL);

    CMD_DisplayCmdKey();

    return ulRet;
}

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
    for (usLoop = 0; usLoop <= CMD_MODE_BUTT; usLoop++)
    {
        g_apstCmdTreeHeads[usLoop] = (CMD_TREE_NODE_S*)BASE_Malloc(sizeof(CMD_TREE_NODE_S));
        CMD_InitCmdSingleTree(usLoop, g_apstCmdTreeHeads[usLoop]);
    }

    return OK;
}

VOID CMD_InitCmdModeString()
{
    BASE_Memcpy(g_acCmdModeStringList[CMD_MODE_GLOBAL], CMD_MODE_GLOBAL_STRING, strlen(CMD_MODE_GLOBAL_STRING));

    return;
}

ULONG CMD_Init()
{
    ULONG ulRet = OK;
    printf("Begin init CmdTree! \n");
    CMD_InitCmdModeString();
    CMD_SetDeafultMode();
    ulRet = CMD_KeyInit();
    return ulRet;
}

ULONG CMD_GetCmdMode()
{
    return g_iCmdMode;
}

CHAR* CMD_GetCmdModeString()
{
    ULONG ulCmdMode;
    ulCmdMode = CMD_GetCmdMode();

    return g_acCmdModeStringList[ulCmdMode];
}

VOID CMD_CmdEntry()
{
    CHAR* pcCmdModeString;
    CHAR  acInputString[MAX_CMD_LEN];
    BOOL  bDealFlag = FALSE;

	while (TRUE) 
    {
        pcCmdModeString = CMD_GetCmdModeString();
        printf("<%s>", pcCmdModeString);
        fgets(acInputString, MAX_CMD_LEN, stdin);  //使用fgets是安全的
        printf("%s", acInputString);
    }
    
    return;
}