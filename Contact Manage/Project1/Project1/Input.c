#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MaxInputLength 100
#define _INPUT_TYPE(x) "%"#x"s"
#define INPUT_TYPE(x) _INPUT_TYPE(x)

/*
 *   ��ȡ�û�������ַ���
 *   ����char�������ָ�� char����Ӧ��Ҫ >= MaxInputLength + 1 (��Ҫ��'\0')
 *   ֻ������100���ַ����ڵ��ַ���
 */
void GetStrUserInput(char * cInput)
{
    int nTemp = 0;/*�建����*/
    int nCount = 0;

    /*����ǰ ��Ҫ����ǰ�����������*/
    for (nCount = 0; nCount < MaxInputLength; nCount++)
    {
        cInput[nCount] = '\0';
    }

    printf("�������100���ַ�  �ո���߻س���������\r\n");
    scanf(INPUT_TYPE(MaxInputLength), cInput);
    while ((nTemp = getchar()) != '\n' && nTemp != EOF);

    return;
}
