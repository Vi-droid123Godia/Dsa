#include <bits/stdc++.h>
using namespace std;

int findPeak(int a[],int n,int low,int high){
    int mid=low+(high-low)/2;
    if((mid==0 or a[mid-1]<=a[mid]) and (mid==n-1 or a[mid]>=a[mid+1])) return mid;
    else if(mid>0 and a[mid-1]>a[mid]) return findPeak(a,n,low,mid-1);
    else return findPeak(a,n,mid+1,high);
}

int main() {
	int a[]={0,6,8,5,7,9};
	cout<<findPeak(a,6,0,5)<<"\n";
	return 0;
}