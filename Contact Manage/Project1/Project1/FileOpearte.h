#ifndef ContactManage_Project1_FileOpearte_H_
#define ContactManage_Project1_FileOpearte_H_

/*���ڴ��ļ�*/
int OpenMemoryFile(void);

/*�ر��ڴ��ļ�*/
int CloseMemoryFile(void);

/*�ڴ�����д��*/
int MemoryWrite(void *buffer, size_t nSize);

/*�ڴ����ݶ�ȡ*/
int MemoryRead(void *buffer, size_t nSize);
#endif //ContactManage_Project1_FileOpearte_H_
