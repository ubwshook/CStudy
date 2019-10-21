#include "base/base.h"
#include "cmd/cmd.h"

ULONG main()
{
	INT iNum = 1;
	ULONG ulRet = OK;
    printf("hello from Algorithm! %d \n", iNum);
	ulRet = CMD_Init();

    return ulRet;
}