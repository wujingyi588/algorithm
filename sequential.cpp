#include <stdio.h>
int Search(int T[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (x == T[i])
            return i;
    }
    return 0;
}
int main()
{
    int T[100], n, x;
    printf("输入数组个数：");
    scanf_s("%d", &n);
    printf("输入数组值：");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &T[i]);
    printf("输入要查找的数：");
    scanf_s("%d", &x);
    printf("输出该数的下标：");
    printf("%d\n", Search(T, n, x));
    return 0;
}