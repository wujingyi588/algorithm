#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}
int minDistance(string str1, string str2) {
	int s1 = str1.size();
	int s2 = str2.size();
	int i, j;
	int f[10][10] = { 0 };
	//≥ı ºªØf[0][0°≠s1]°¢f[0°≠s2][0] 
	for (i = 1; i <= s1; i++) {
		f[i][0] = i;
	}
	for (i = 1; i <= s2; i++) {
		f[0][i] = i;
	}

	for (i = 1; i <= s1; i++) {
		for (j = 1; j <= s2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				f[i][j] = f[i - 1][j - 1];
			}
			else {
				f[i][j] = min(min(f[i - 1][j - 1], f[i][j - 1]), f[i - 1][j]) + 1;
			}
		}
	}
	return f[s1][s2];
}
int main() {
	string str1, str2;
	cin >> str1;
	cin >> str2;
	cout << minDistance(str1, str2)<< endl;
	return 0;
}