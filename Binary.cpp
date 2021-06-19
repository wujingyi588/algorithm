#include <stdio.h>
#include <math.h>
int Binary_Search(int T[], int n, int x)
{
    int high = n;
    int low = 1;
    int m;
    while (low <= high)
    {
        m = floor((high + low) / 2.0);
        if (x < T[m])
            high = m - 1;
        else if (x > T[m])
            low = m + 1;
        else
            return m;
    }
    return 0;
}
int main()
{
    int T[100], n, x;
    printf("输入数组个数：");
    scanf_s("%d", &n);
    printf("输入数组的值：");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &T[i]);
    printf("输入要查找的数：");
    scanf_s("%d", &x);
    printf("输出该数的下标：");
    printf("%d\n", Binary_Search(T, n, x));
    return 0;
}