#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#define max 90000000
#define maxV 500
//����ͼ 
int main() {
    int n, m, a, b, v, i, j, min, k;
    printf("���붥�����ͱ�����");
    scanf_s("%d%d", &n, &m);
    int g[maxV][maxV], d[maxV], vis[maxV];
    memset(vis, 0, sizeof(vis));
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            g[i][j] = max;
        }
        d[i] = max;
    }
    printf("����ߵ��ߵ�Ȩֵ��\n");
    for (i = 0; i < m; i++) {
        scanf_s("%d%d%d", &a, &b, &v);
        g[a][b] = v;
    }
    for (i = 2; i <= n; i++) {
        d[i] = g[1][i]; //��ʼ��Դ�㵽i���Ȩֵ
    }
    vis[1] = 1;
    for (i = 2; i <= n; i++) {
        min = max;
        for (j = 2; j <= n; j++) {
            if (d[j] < min && vis[j] == 0) {
                min = d[j];
                k = j;
            }
        }
        vis[k] = 1;
        for (j = 2; j <= n; j++) {
            if (d[j] > d[k] + g[k][j] && vis[j] == 0) { 
                d[j] = d[k] + g[k][j];
            }
        }
    }
    printf("�������1���������̾��룺\n");
    for (i = 2; i <= n; i++) {
        printf("1->%d:%d\n", i, d[i]);
    }
    return 0;
}