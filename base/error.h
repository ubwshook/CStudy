#ifndef _ERROR_H_ 
#define _ERROR_H_

typedef enum eBaseErrorCode
{
    ERROR_MALLOC_FAIL = 1,         /* �ڴ濪��ʧ�� */
    ERROR_INVALID_CMD_CHAR = 2,    /* �Ƿ��������ַ� */
    ERROR_GENERAL_ERROR = 3,       /* һ���Դ��� */
    ERROR_STACK_FULL = 4,          /* ջ���� */
    ERROR_STACK_EMPTY = 5,         /* ջ�ǿյ� */
    ERROR_TREE_NO_PARENT = 6,      /* û���ҵ����ڵ� */
    ERROR_BUTT

}BASE_ERROR_CODE_EN;

#endif
