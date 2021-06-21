#include<stdio.h>
#define MAX 100
int c[MAX][MAX], b[MAX][MAX],d[MAX];
void LongChain(int x[],int y[],int m,int n){
	c[0][0] = { 0 };
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i-1] == y[j-1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 2;	//2��ʾɾ������
			}
			else if (c[i][j - 1] >= c[i - 1][j]) {
				c[i][j] = c[i][j - 1];
				b[i][j] = 1;	//1��ʾɾ��y
			}
			else {
				c[i][j] = c[i - 1][j];
				b[i][j] = 0;	//0��ʾɾ��x
			}
		}
	}
}
void f(int x[],int i,int j) {
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 2) {
		f(x, i - 1, j - 1);
		printf("%d ", x[i - 1]);	//��b[i][j]==2ʱ����ʾ��Ԫ��Ϊ�������еĹ���Ԫ�أ��������Ԫ��
	}
	else if (b[i][j] == 0) {
		f(x, i - 1, j);
	}
	else
	{
		f(x, i, j - 1);
	}
}
int main()
{
	int x[] = { 1,2,3,4,2,5 };
	int y[] = { 2,4,1,3,5 };
	LongChain(x, y, 6, 5);
	f(x, 6, 5);
	return 0;
}
/*
��x= 1,2,3,4,2,5 ,y= 2,4,1,3,5ʱ
����������Ϊ2 4 5
*/

