#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k; cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;++i) cin>>a[i];
	map<int,int> m;
	for(int i=0;i<n;++i){
	    int p=m.size();
	    if(m[a[i]]==0 and p==k) break;
	    m[a[i]]++;
	}
	vector<pair<int,int> > ans;
	for(auto i:m){
	    if(i.second!=0) ans.push_back({i.second,i.first});
	}
	sort(ans.begin(),ans.end(),greater<pair<int,int>>());
	for(auto i:ans){
	    cout<<i.second<<"->"<<i.first<<"\n";
	}
	return 0;
}