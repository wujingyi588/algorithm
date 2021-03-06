#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int n, t;
int p[1010], dp[1010][1010], ans[1010][1010];
void outans(int i, int j) {
	if (i == j) printf("A%d", i);
	else {
		printf("(");
		outans(i, ans[i][j]);
		outans(ans[i][j] + 1, j);
		printf(")");
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++)	dp[i][i] = 0;
	for (int dis = 2; dis <= n; dis++) {
		for (int i = 1; i + dis - 1 <= n; i++) {
			int j = i + dis - 1;
			dp[i][j] = inf;
			for (int k = i; k < j; k++) {
				t = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < dp[i][j]) {
					dp[i][j] = t;
					ans[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", dp[1][n - 1]);
	outans(1, n - 1);
}

