#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "FileOpearte.h"

int main(void)
{
    char arycArray[20] = { "Œ“TM…Á±£" };
    char arycTemp[20] = { '\0' };

    OpenMemoryFile();

    MemoryWrite(arycArray, 8);

    MemoryRead(arycTemp, 8);

    printf("%s\r\n", arycTemp);

    CloseMemoryFile();
    system("pause");
    return 0;
}