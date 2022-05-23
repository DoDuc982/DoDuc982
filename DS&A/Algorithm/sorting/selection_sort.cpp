#include<iostream>
using namespace std;
void selection_sort(int a[], int n){
	for(int i = 0; i < n; i++){
		int index = i;
		for(int j=i; j<n;j++) if(a[index]>a[j]) index = j;
		int temp = a[index];
		a[index] = a[i];
		a[i]=temp;
	}
}
int main(){
	int n;	cin>>n;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	selection_sort(a,n);
	for(int x:a) cout<<x<<" ";
}
