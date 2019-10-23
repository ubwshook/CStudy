#include "base/base.h"
#include "cmd/cmd.h"

ULONG main()
{
	ULONG ulRet = OK;
	ulRet = CMD_Init();
	CMD_CmdEntry();

	return ulRet;
}