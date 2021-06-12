#include <bits/stdc++.h>
using namespace std;

const int N=1e3+2;
vector<vector<int>> dp(N,vector<int>(N,-1));

long long helper(int a[],int i,int j){
    if(i==j) return a[i];
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int l=(a[i]+min(helper(a,i+2,j),helper(a,i+1,j-1)));
    int r=(a[j]+min(helper(a,i,j-2),helper(a,i+1,j-1)));
    return dp[i][j]=max(l,r);
}

//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int a[], int n) {
    int i=0,j=n-1;
    return helper(a,i,j);
}

int main() {
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    
    cout<<maximumAmount(a,n)<<"\n";
	return 0;
}