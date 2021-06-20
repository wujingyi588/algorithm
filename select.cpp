#include <stdio.h>
#include <stdlib.h>

int B[1000];
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


int select(int a[], int left, int right, int k)
{
	int n = right - left;
	if (n < 5)
	{
		MergeSort(a, left, right - 1);
		return a[left + k - 1];
	}
	int i;
	int s = n / 5;
	int* m = new int[s];//中位数数组
	for (i = 0; i < s; i++)
	{
		MergeSort(a, left + i * 5, left + i * 5 + 5 - 1);
		m[i] = a[left + i * 5 + 2];
	}
	MergeSort(m, 0, i - 1);
	int mid = m[i / 2];
	int* a1 = new int[n];
	int* a2 = new int[n];
	int* a3 = new int[n];
	int num1 = 0, num2 = 0, num3 = 0;
	for (int i = left; i < right; i++)
	{
		if (a[i] < mid)
		{
			a1[num1++] = a[i];
		}
		else if (a[i] == mid)
		{
			a2[num2++] = a[i];
		}
		else
			a3[num3++] = a[i];
	}
	if (num1 >= k)
	{
		return select(a1, 0, num1, k);
	}
	if (num1 + num2 >= k)
	{
		return mid;
	}
	else
		return select(a3, 0, num3, k - num1 - num2);
}

int main()
{
	int n;
	printf("请输入数组大小：");
	scanf_s("%d", &n);
	int a[1000];
	printf("请输入数组的值：\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
	}
	int k;
	printf("请输入所求的第几小元素：");
	scanf_s("%d", &k);
	printf("第%d小元素：", k);
	printf("%d\n", select(a, 0, n, k));
	return 0;
}
