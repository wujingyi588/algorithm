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
    printf("�������������");
    scanf_s("%d", &n);
    printf("���������ֵ��");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &T[i]);
    printf("����Ҫ���ҵ�����");
    scanf_s("%d", &x);
    printf("����������±꣺");
    printf("%d\n", Binary_Search(T, n, x));
    return 0;
}