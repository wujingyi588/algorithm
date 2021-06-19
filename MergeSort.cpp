#include<stdio.h>
#include<math.h>
int B[100000];
void Merge(int A[], int low, int mid, int high)
{
	int x = low, y = low, z = mid + 1;
	while (x <= mid && z <= high)
	{
		if (A[x] < A[z])B[y++] = A[x++];
		else B[y++] = A[z++];
	}
	while (x <= mid)
	{
		B[y++] = A[x++];
	}
	while (z <= high)
	{
		B[y++] = A[z++];
	}
	for (y = low; y <= high; y++)
	{
		A[y] = B[y];
	}
}

void MergeSort(int A[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(A, low, mid);//排序左半边
		MergeSort(A, mid + 1, high);//排序右半边
		Merge(A, low, mid, high);// 将左半边和右半边结合起来归并
	}
}

int main() {
	int k, n, i;
	int A[100000];
	printf("输入k的值：");
	scanf_s("%d", &k);
	n = pow(2, k);
	printf("输入2^k个数组值：");
	for (i = 1; i <= n; i++) {
		scanf_s("%d", &A[i]);
	}
	MergeSort(A, 1, n);
	printf("输出排序好的数组：\n");
	for (i = 1; i <= n; i++) {
		printf("%d ", A[i]);
	}
	return 0;
}