#include "base/base.h"
#include "cmd/cmd.h"
#include "base/data_structure.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <ncurses/curses.h>


ULONG main()
{
    ULONG ulRet = OK;
    CHAR  acInputString[MAX_CMD_LEN];
    CMD_Init();
    CMD_CmdEntry();

    return ulRet;
}
