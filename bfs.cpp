#include <bits/stdc++.h>
using namespace std;

const int N=1e5+2;
vector<bool> visited(N,false);
vector<int> adj[N];

int main() {
	int n,m; cin>>n>>m;
	for(int i=0;i<m;++i){
	    int x,y; cin>>x>>y;
	    adj[x].push_back(y);
	    adj[y].push_back(x);
	}
	queue<int> q;
	q.push(1);
	visited[1]=true;
	while(!q.empty()){
	    int node=q.front();
	    q.pop();
	    cout<<node<<" ";
	    for(auto i:adj[node]){
	        if(!visited[i]){
	            visited[i]=true;
	            q.push(i);
	        }
	    }
	}
	return 0;
}