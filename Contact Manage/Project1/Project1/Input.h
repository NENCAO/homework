
#ifndef ContactManage_Project1_Input_H_
#define ContactManage_Project1_Input_H_

/*替换scanf()的 %100s*/
#define _INPUT_TYPE(x) "%"#x"s"
#define INPUT_TYPE(x) _INPUT_TYPE(x)

/*用户可以输入的最大字节数*/
#define MaxInputLength 100

/*内存文件的最大字节数*/
#define MAXSIZE 500

/*获取用户通讯录的输入 限制MaxInputLength个字符输入*/
void GetStrUserInput(char * szUserName, char * szUserPhone, char *szUserAddress);

/*获取用户输入的长度*/
int GetStrLength(char *szUserInput);

/*获取用户输入的数字*/
int GetIntUserInput(void);

/*获取用户输入的模糊查找字符串 限制MaxInputLength个字符输入*/
void GetUserFindInput(char * cInput);
#endif //ContactManage_Project1_Input_H_