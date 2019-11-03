#ifndef _ERROR_H_ 
#define _ERROR_H_

typedef enum eBaseErrorCode
{
    ERROR_MALLOC_FAIL = 1,         /* 内存开辟失败 */
    ERROR_INVALID_CMD_CHAR = 2,    /* 非法命令行字符 */
    ERROR_GENERAL_ERROR = 3,       /* 一般性错误 */
    ERROR_STACK_FULL = 4,          /* 栈已满 */
    ERROR_STACK_EMPTY = 5,         /* 栈是空的 */
    ERROR_TREE_NO_PARENT = 6,      /* 没有找到父节点 */
    ERROR_BUTT

}BASE_ERROR_CODE_EN;

#endif
