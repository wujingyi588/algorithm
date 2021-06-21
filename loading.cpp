#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void BubbleSort(int *arr, int len){
	for (int i = 0; i < len - 1; ++i){
		int flag = 0;
		for (int j = 0; j < len - 1 - i; ++j){
			if (arr[j] > arr[j + 1]){
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}

		if (flag == 0){
			break;
		}
	}
}

int main(){
	int n,B,i,j=0,w[100],t=0;
	cout<<"请输入集装箱个数：";
	cin>>n;
	cout<<"请输入轮船的最大载重量：";
	cin>>B;
	
	cout<<"请依次输入集装箱的重量："<<endl;
	for(i=0;i<n;i++){
	    cin>>w[i];
	}
	
	BubbleSort(w,n);
	for(j=0;j<n;j++){
		if(t+w[j]>B)
			break;
		t+=w[j];
	} 
	cout<<endl<<"轮船最多装"<<j<<"个集装箱，重量分别为：";
	for(i=0;i<j;i++){
	    cout<<w[i]<<" "; 
	}
	cout<<endl;
	return 0;
}



