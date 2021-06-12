#include <bits/stdc++.h>
using namespace std;

const int N=1e3+2;
int val[N],wt[N];
int dp[N][N];

// int knapsack(int n,int w){
//     if(w<=0) return 0;
//     if(n<=0) return 0;
//     if(dp[n][w]!=-1) return dp[n][w];
//     if(w<wt[n-1]) dp[n][w]=knapsack(n-1,w);
//     else dp[n][w]=max(knapsack(n-1,w),knapsack(n-1,w-wt[n-1])+val[n-1]);
//     return dp[n][w];
// }

int main() {
//     for(int i=0;i<N;++i){
// 	    for(int j=0;j<N;++j){
// 	        dp[i][j]=-1;
// 	    }
// 	}
	int n; cin>>n;
	for(int i=0;i<n;++i) cin>>wt[i];
	for(int i=0;i<n;++i) cin>>val[i];
	int w; cin>>w;
// 	cout<<knapsack(n,w)<<"\n";
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<n+1;++i){
        for(int j=0;j<w+1;++j){
            dp[i][j]=dp[i-1][j];
            if(j-wt[i-1]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-wt[i-1]]+val[i-1]);
        }
    }
    cout<<dp[n][w]<<"\n";
	return 0;
}