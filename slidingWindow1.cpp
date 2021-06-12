#include <bits/stdc++.h>
using namespace std;

int smallestSubarray(int a[],int n,int x){
    int sum=0,minLength=n+1,start=0,end=0;
    while(end<n){
        while(sum<=x and end<n){
            sum+=a[end++];
        }
        while(sum>x and start<=end){
            if((end-start)<minLength) minLength=(end-start);
            sum-=a[start++];
        }
    }
    return minLength;
}

int main() {
	int a[]={1,4,45,6,10,19};
	int x=51;
	int n=6;
	int minLength=smallestSubarray(a,n,x);
	if(minLength==n+1) cout<<"No such array present";
	else cout<<minLength;
	cout<<"\n";
	return 0;
}