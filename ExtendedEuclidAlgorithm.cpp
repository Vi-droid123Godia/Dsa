#include <bits/stdc++.h>
using namespace std;

struct triplet{
    int x,y,gcd;
};

triplet extendedEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.gcd=a;
        ans.y=0;
        return ans;
    }
    triplet ans;
    triplet sans=extendedEuclid(b,a%b);
    ans.x=sans.y;
    ans.gcd=sans.gcd;
    ans.y=sans.x-(a/b)*sans.y;
    return ans;
}

int main() {
	int a,b; cin>>a>>b;
	triplet ans=extendedEuclid(a,b);
	cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<"\n";
	return 0;
}