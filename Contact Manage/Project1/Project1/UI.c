#include <stdio.h>


/*
 *   �Զ����ӡ�ַ����ĺ���
 *   ����sz���͵��ַ���
 *   ��ӡ������ַ���
 */
void MyPrint(char *szStr)
{
    printf("%s", szStr);
}


/*
 *   �û���ʼ����
 *   �޲��� ���߼�����
 *   ��������ʾ����
 */
void StartInterface(void)
{
    int nCount = 0;

    for (nCount = 0; nCount < 40; nCount++)
    {
        MyPrint("* ");
    }
    MyPrint("\r\n");
    MyPrint("* ");

    for (nCount = 0; nCount <= 20; nCount++)
    {
        MyPrint(" ");
    }

    MyPrint("Dynamic Management System");

    for (nCount = 0; nCount < 30; nCount++)
    {
        MyPrint(" ");
    }
    MyPrint("* ");
    MyPrint("\r\n");

    for (nCount = 0; nCount < 40; nCount++)
    {
        MyPrint("* ");
    }

    MyPrint("\r\n");

    MyPrint("1.�����ַ���         2.ɾ���ַ���\
             3.�޸��ַ���         4.��ѯ�ַ���\
         \r\n5.ͳ����ĸ           6.�鿴�洢��Ϣ\
           7.��Ƭ����");

    MyPrint("\r\n");
}