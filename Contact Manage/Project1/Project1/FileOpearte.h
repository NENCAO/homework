#ifndef ContactManage_Project1_FileOpearte_H_
#define ContactManage_Project1_FileOpearte_H_

#include<stdio.h>
#define SAFE_FREE(p) if(p){free(p);p=NULL;}

struct tagManger
{
    int isOccupy;
    int nOffset;
    int nSize;
    struct tagManger *pstNext;
};

struct tagMangerData
{
    int isOccupy;
    int nOffset;
    int nSize;
};

/*打开内存文件*/
void OpenMemoryFile(void);

/*关闭内存文件*/
void CloseMemoryFile(void);

/*内存数据写入*/
void MemoryWrite(void *buffer, size_t nSize);

/*内存数据读取*/
void MemoryRead(void *buffer, size_t nSize);


/*打开管理文件*/
void OpenManagerFile(void);

/*关闭管理文件*/
void CloseManagerFile(void);

/*读取管理表*/
void ManagerRead(void *buffer, size_t nSize, size_t nOffset);

/*管理表从文件写入内存中*/
void CreatManagerList(void);

/*管理表从内存写入文件*/
void WriteManagerToFile(void);

/*字符串从文件写入内存中*/
void CreatMemoryList(void);

/*字符串从内存写入文件*/
void WritMemoryToFile(void);
#endif //ContactManage_Project1_FileOpearte_H_

