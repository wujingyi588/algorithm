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
    printf("�������������");
    scanf_s("%d", &n);
    printf("��������ֵ��");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &T[i]);
    printf("����Ҫ���ҵ�����");
    scanf_s("%d", &x);
    printf("����������±꣺");
    printf("%d\n", Search(T, n, x));
    return 0;
}