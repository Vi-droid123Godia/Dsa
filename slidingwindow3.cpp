#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    int temp=n,number=0;
    while(temp>0){
        number=number*10+temp%10;
        temp/=10;
    }
    if(number==n) return true;
    else return false;
}

int palindromeSubarray(vector<int> a,int k){
    int num=0;
    for(int i=0;i<k;++i){
        num=num*10+a[i];
    }
    if(isPalindrome(num)) return 0;
    for(int i=k;i<a.size();++i){
        num=(num%(int)pow(10,k-1))*10 +a[i];
        if(isPalindrome(num)) return i-k+1;
    }
    return -1;
}

int main() {
	vector<int> a={2,3,5,1,1,5};
	int k=4;
	int ans=palindromeSubarray(a,k);
	if(ans==-1) cout<<"No such subarray";
	else{
	    for(int i=ans;i<ans+k;++i) cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}