#include <bits/stdc++.h>
using namespace std;

struct triplet{
  int x,y,gcd;  
};

triplet extendedEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet sans=extendedEuclid(b,a%b);
    triplet ans;
    ans.x=sans.y;
    ans.gcd=sans.gcd;
    ans.y=sans.x-(a/b)*sans.y;
    return ans;
}

int multiplicativeModuloInverse(int a,int m){
    triplet ans=extendedEuclid(a,m);
    return ans.x;
}

int main() {
    int t; cin>>t;
    while(t--){
        int a,m; cin>>a>>m;
        cout<<multiplicativeModuloInverse(a,m)<<"\n";
    }
    return 0;
}