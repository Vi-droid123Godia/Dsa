#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int> b){
    double v1=double (a.first)/double (a.second);
    double v2=double (b.first)/double (b.second);
    return v1>v2;
}

int main(){
    int n; cin>>n;
    vector<pair<int,int> > a(n);
    for(int i=0;i<n;++i){
        cin>>a[i].first>>a[i].second;
    }
    int weight; cin>>weight;
    sort(a.begin(),a.end(),compare);
    int ans=0;
    for(int i=0;i<n;++i){
        if(weight>=a[i].second){
            ans+=a[i].first;
            weight-=a[i].second;
            continue;
        }
        double vw=double(a[i].first)/double(a[i].second);
        ans+=vw*weight;
        weight=0;
        break;
    }
    cout<<ans<<"\n";
    return 0;
}