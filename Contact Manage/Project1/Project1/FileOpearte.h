#ifndef ContactManage_Project1_FileOpearte_H_
#define ContactManage_Project1_FileOpearte_H_

/*打开内存文件*/
int OpenMemoryFile(void);

/*关闭内存文件*/
int CloseMemoryFile(void);

/*内存数据写入*/
int MemoryWrite(void *buffer, size_t nSize);

/*内存数据读取*/
int MemoryRead(void *buffer, size_t nSize);
#endif //ContactManage_Project1_FileOpearte_H_
