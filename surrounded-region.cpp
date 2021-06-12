#include <bits/stdc++.h>
using namespace std;

void change(vector<vector<char>> &a,int x,int y){
    a[x][y]='*';
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};
    for(int i=0;i<4;++i){
        int cx=x+dx[i];
        int cy=y+dy[i];
        if(cx>=0 and cx<a.size() and cy>=0 and cy<a[0].size() and a[cx][cy]=='O') change(a,cx,cy);
    }
}

int main() {
	int n,m; cin>>n>>m;
	vector<vector<char>> a(n,vector<char>(m));
	for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>a[i][j];
        }
	}
	for(int i=0;i<n;++i){
	    for(int j=0;j<m;++j){
	        if(i==0 or i==n-1 or j==0 or j==m-1){
	            if(a[i][j]=='O') change(a,i,j);
	        }
	    }
	}
	for(int i=0;i<n;++i){
	    for(int j=0;j<m;++j){
	        if(a[i][j]=='O') a[i][j]='X';
	    }
	}
	for(int i=0;i<n;++i){
	    for(int j=0;j<m;++j){
	        if(a[i][j]=='*') a[i][j]='O';
	    }
	}
	for(int i=0;i<n;++i){
	    for(int j=0;j<m;++j){
	        cout<<a[i][j]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}