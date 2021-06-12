#include <bits/stdc++.h>
using namespace std;

const int N=1e5+2;
vector<bool> visited(N,false);
vector<int> adj[N];

void dfs(int node){
    visited[node]=true;
    for(int i:adj[node]){
        if(!visited[i]) dfs(i);
    }
    cout<<node<<" ";
}

int main() {
	int n,m; cin>>n>>m;
	for(int i=0;i<m;++i){
	    int x,y; cin>>x>>y;
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	}
	dfs(1);
	return 0;
}