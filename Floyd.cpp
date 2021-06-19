#include<stdio.h>
#include<stdlib.h>
#define max 1000000000

int d[1000][1000], path[1000][1000];
int main()
{
    int i, j, k, m, n;
    int x, y, z;
    printf("�����ͱ�����");
    scanf_s("%d%d", &n, &m);         //�����ͱ���

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            d[i][j] = max;
            path[i][j] = j;
        }
    printf("����ÿ������֮��Ĵ�Ȩ·��:\n");
    for (i = 1; i <= m; i++) {
        scanf_s("%d%d%d", &x, &y, &z);       //����ÿ������֮��Ĵ�Ȩ·��
        d[x][y] = z;
    }

    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    printf("����㵽��֮������·����\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j) printf("%d->%d:%d\n", i, j, d[i][j]);
    return 0;
}