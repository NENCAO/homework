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

/*���ڴ��ļ�*/
void OpenMemoryFile(void);

/*�ر��ڴ��ļ�*/
void CloseMemoryFile(void);

/*�ڴ�����д��*/
void MemoryWrite(void *buffer, size_t nSize);

/*�ڴ����ݶ�ȡ*/
void MemoryRead(void *buffer, size_t nSize);


/*�򿪹����ļ�*/
void OpenManagerFile(void);

/*�رչ����ļ�*/
void CloseManagerFile(void);

/*��ȡ�����*/
void ManagerRead(void *buffer, size_t nSize, size_t nOffset);

/*�������ļ�д���ڴ���*/
void CreatManagerList(void);

/*�������ڴ�д���ļ�*/
void WriteManagerToFile(void);

/*�ַ������ļ�д���ڴ���*/
void CreatMemoryList(void);

/*�ַ������ڴ�д���ļ�*/
void WritMemoryToFile(void);
#endif //ContactManage_Project1_FileOpearte_H_

