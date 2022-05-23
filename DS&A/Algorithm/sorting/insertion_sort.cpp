#include<iostream>
using namespace std;
void insertion_sort(int a[], int n){
	for(int i = 1; i < n; i++){
		int x = a[i], index = i-1;
		while (x<a[index] && index>=0){
			a[index+1]=a[index];
			index--;
		}
		a[index+1]=x;
	}
}
int main(){
	int n;	cin>>n;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	insertion_sort(a,n);
	for(int x:a) cout<<x<<" ";
}
