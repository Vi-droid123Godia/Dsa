#include <bits/stdc++.h>
using namespace std;

int search(int a[],int n,int key,int left,int right){
    if(left>right) return -1;
    int mid=(left+right)/2;
    if(a[mid]==key) return mid;
    if(a[left]<=a[mid]){
        if(key>=a[left] and key<=a[mid]) return search(a,n,key,left,mid-1);
        return search(a,n,key,mid+1,right);
    }else{
        if(key>=a[mid] and key<=a[right]) return search(a,n,key,mid+1,right);
        return search(a,n,key,left,mid-1);
    }
}

int main() {
	int a[]={6,7,8,9,10,1,2,5};
	int n=8,key=8;
	cout<<search(a,n,key,0,n-1)<<"\n";
	return 0;
}