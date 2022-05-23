#include <bits/stdc++.h> 
using namespace std;
bool binary_search_recursion(int arr[], int, int, int); 
bool exponential_search(int arr[], int n, int x){ 
	//check the first element
    if (arr[0] == x) 
        return 0; 
    int i = 1; 
    //implement search, arr[i] to lock the distance
    while (i < n && arr[i] <= x) 
        i = i*2; 
    return binary_search_recursion(arr, i/2, min(i, n), x); 
} 
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
int main(void) 
{ 
   int arr[] = {2, 3, 4, 10, 40}; 
   int n = sizeof(arr)/ sizeof(arr[0]); 
   int x = 10; 
	cout<<exponential_search(arr, n, x);
   return 0; 
} 

