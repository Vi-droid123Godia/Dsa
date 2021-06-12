#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> colour;
bool biparte;

void color(int idx,int curr){
    if(colour[idx]!=-1 and colour[idx]!=curr){
        biparte=false;
        return;
    }
    colour[idx]=curr;
    if(visited[idx]) return;
    visited[idx]=true;
    for(auto i:adj[idx]) color(i,curr xor 1);
}

int main() {
    biparte=true;
    int n,m; cin>>n>>m;
	adj=vector<vector<int>>(n);
	visited=vector<bool>(n,false);
	colour=vector<int>(n,-1);
	for(int i=0;i<m;++i){
	    int u,v; cin>>u>>v;
	    adj[u].push_back(v);
	    adj[v].push_back(u);
	}
	
	for(int i=0;i<n;++i){
	    if(!visited[i]) color(i,0);
	}
	if(biparte) cout<<"Graph is bipartite.\n";
	else cout<<"Graph is not bipartite.\n";
	return 0;
}