#include<iostream>
using namespace std;
//binary_search without recursion
bool binary_search(int a[], int n, int x){
	int l=0;
	int r=n-1;
	while (l<=r){
		//find the middle
		int m = (l+r)/2;
		//check middle
		if(a[m]==x) return true;
		else if (a[m]<x) {
			l=m+1;
		}
		
		else r=m-1;
	}
	return false;
}
//bianry_search with recursion
bool binary_search_recursion(int a[], int l, int r, int x){
	int m=(l+r)/2;
	//find middle
	if(l>r){
		return false;
	}
	//check middle number
	if (a[m]==x) return true;
	else if (a[m]<x) binary_search_recursion(a,m+1,r,x);
	else binary_search_recursion(a,l,m-1,x);
}
int main(){
	int n;	cin>>n;
	int a[n];
	for (int x:a) cin>>x;
	int k;	cin>>k;
	cout<<binary_search(a,n,k)<<endl;
	cout<<binary_search_recursion(a,0,n-1,k);
}
