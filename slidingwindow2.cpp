#include <bits/stdc++.h>
using namespace std;

void compute(vector<int> a,int k){
    pair<int,int> ans;
    int sum=0;
    for(int i=0;i<k;++i) sum+=a[i];
    bool found=false;
    if(sum%3==0){
        found=true;
        ans=make_pair(0,k-1);
    }
    for(int i=k;i<a.size();++i){
        if(found) break;
        sum+=a[i]-a[i-k];
        if(sum%3==0){
            ans=make_pair(i-k+1,i);
            found=true;
        }
    }
    if(!found) ans=make_pair(-1,0);
    if(ans.first==-1){
        cout<<"No subarray present";
    }else{
        for(auto i=ans.first;i<=ans.second;++i) cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main() {
	vector<int> a={23,45,12,56,82};
	int k=3;
    compute(a,3);
	return 0;
}