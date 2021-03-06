#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int a[101];
void quicksort(int left, int right);
void swap(int left, int right);
int main(void)
{
    int n , i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    quicksort(0, n-1);

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    getchar();
}

void quicksort(int left, int right)
{
    if (left > right)//递归条件
    {
        return;
    }
    int front, after, base;
    front = left - 1; //前指针
    after = left;  //后指针
    base = a[right]; //以右边为基准

    while (after < right) //后指针到达右边界
    {
        while (a[after] < base && ++front != after)//条件不可换位置 注意&&的特性
        {
            swap(front, after);//交换
        }
        after++;//
    }
    swap(++front, right);//front跳出时没有移动 需要移动后再传入

    //递归
    quicksort(front + 1, right);
    quicksort(left, front - 1);
}

void swap(int left, int right)
{
    int t;
    t = a[right]; //放入暂存
    int i = 0;
    while (right - i > left)//检测指针是否已经到最后了
    {
        a[right - i] = a[right - i - 1];//全部向前移动一位
        i++;
    }
    a[left] = t;//换回去
}