#ifndef ContactManage_Project1_UI_H_
#define ContactManage_Project1_UI_H_

/*自定义输入*/
void MyPrint(char *szStr);

/*开始界面*/
void StartInterface(void);

/*显示当前内存中有的数据*/
void ShowInputString(void);

/*显示输入的字符串*/
void ShowFindString(char *pcTemp, struct tagManger *stMangerTemp);
#endif //ContactManage_Project1_UI_H_
