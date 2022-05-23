#include<iostream>
using namespace std;
int interpolation_search(int a[], int n, int x){
	int l = 0, r = n-1;
	while (a[r] != a[l] && x >= a[l] && x <= a[r]){
		int mid = l + (r-l)*(x-a[l])/(a[r]-a[l]);
		if (a[mid] < x){
			l = mid + 1;
		} else if (a[mid] > x) {
			r = mid - 1;
		} else{
			return mid;
		}
	}
	//Khong tim thay thì return -1
	return -1;
}
int main(){
	int n;	cin>>n;
	int a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int x;	cin>>x;
	cout<<interpolation_search(a,n,x);
}
