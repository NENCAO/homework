
#ifndef ContactManage_Project1_Input_H_
#define ContactManage_Project1_Input_H_

/*�滻scanf()�� %100s*/
#define _INPUT_TYPE(x) "%"#x"s"
#define INPUT_TYPE(x) _INPUT_TYPE(x)

/*�û��������������ֽ���*/
#define MaxInputLength 100

/*�ڴ��ļ�������ֽ���*/
#define MAXSIZE 500

/*��ȡ�û�ͨѶ¼������ ����MaxInputLength���ַ�����*/
void GetStrUserInput(char * szUserName, char * szUserPhone, char *szUserAddress);

/*��ȡ�û�����ĳ���*/
int GetStrLength(char *szUserInput);

/*��ȡ�û����������*/
int GetIntUserInput(void);

/*��ȡ�û������ģ�������ַ��� ����MaxInputLength���ַ�����*/
void GetUserFindInput(char * cInput);
#endif //ContactManage_Project1_Input_H_