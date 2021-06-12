#include<bits/stdc++.h>
using namespace std;

bool isPossible(int a[],int n,int m,int min){
    int studentsRequired=1,sum=0;
    for(int i=0;i<n;++i){
        if(a[i]>min) return false;
        if(a[i]+sum>min){
            studentsRequired++;
            sum=a[i];
            if(studentsRequired>m) return false;
        }else sum+=a[i];
    }
    return true;
}

int allocateMinimumPages(int a[],int n,int m){
    if(n<m) return -1;
    int sum=0;
    for(int i=0;i<n;++i) sum+=a[i];
    int start=0,end=sum,ans=INT_MAX;
    while(start<end){
        int mid=(start+end)/2;
        if(isPossible(a,n,m,mid)){
            ans=min(ans,mid);
            end=mid-1;
        }else start=mid+1;
    }
    return ans;
}

int main() {
	int a[]={12,34,67,90};
	cout<<allocateMinimumPages(a,4,2)<<"\n";
	return 0;
}