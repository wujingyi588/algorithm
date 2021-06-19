#include<stdio.h>
#include<stdlib.h>
#define max 1000000000

int d[1000][1000], path[1000][1000];
int main()
{
    int i, j, k, m, n;
    int x, y, z;
    printf("输入点和边数：");
    scanf_s("%d%d", &n, &m);         //输入点和边数

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            d[i][j] = max;
            path[i][j] = j;
        }
    printf("输入每两个点之间的带权路径:\n");
    for (i = 1; i <= m; i++) {
        scanf_s("%d%d%d", &x, &y, &z);       //输入每两个点之间的带权路径
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
    printf("输出点到点之间的最短路径：\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (i != j) printf("%d->%d:%d\n", i, j, d[i][j]);
    return 0;
}