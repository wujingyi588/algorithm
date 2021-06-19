#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#define max 90000000
#define maxV 500
//有向图 
int main() {
    int n, m, a, b, v, i, j, min, k;
    printf("输入顶点数和边数：");
    scanf_s("%d%d", &n, &m);//输入n个顶点，m条边 
    int g[maxV][maxV], d[maxV], vis[maxV];//g[i][j]表示i到j的边的权值,vis[i]表示到此顶点的最短路是否已经找到，d[i]当前源点到i顶点的最短路径 
    memset(vis, 0, sizeof(vis));
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            g[i][j] = max;
        }
        d[i] = max;
    }
    printf("输入边到边的权值：\n");
    for (i = 0; i < m; i++) {//i到j的边权值储存到g邻接矩阵中,i点到j点无直接相连的边时，g[i][j]=max  
        scanf_s("%d%d%d", &a, &b, &v);
        g[a][b] = v;
    }
    for (i = 2; i <= n; i++) {
        d[i] = g[1][i]; //初始化源点到i点边权值，之后过程中会发生变化 
    }
    vis[1] = 1;
    for (i = 2; i <= n; i++) {//共循环n-1次，每循环一次，确定一条最短路，再次循环时这条路就不用考虑了，去寻找下一条最短路 
        min = max;
        for (j = 2; j <= n; j++) {//寻找下一条当前最短路 
            if (d[j] < min && vis[j] == 0) {
                min = d[j];
                k = j;
            }
        }
        vis[k] = 1;//找到了，到k点的路是当前最短路，标记它，根据它寻找下一条最短路 
        for (j = 2; j <= n; j++) {
            if (d[j] > d[k] + g[k][j] && vis[j] == 0) {//经过此k点到达j点的路径是否小于其他到达j点的路径 
                d[j] = d[k] + g[k][j];
            }
        }
    }
    printf("输出顶点1到各点的最短距离：\n");
    for (i = 2; i <= n; i++) {//输出到达个点的最短路径 
        printf("1->%d:%d\n", i, d[i]);
    }
    return 0;
}