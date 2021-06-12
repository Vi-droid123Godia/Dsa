#include <bits/stdc++.h>
using namespace std;

vector<int> prefixf(string &s){
    int n=s.size();
    vector<int> pi(n,0);
    for(int i=1;i<n;++i){
        int j=pi[i-1];
        while(j>0 and s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}

int main() {
	string s="na";
	vector<int> res=prefixf(s);
	string t="apnacollege";
	int pos=-1;
	int i=0,j=0;
	while(i<t.size()){
	    if(s[j]==t[i]){
	        i++;
	        j++;
	    }else{
	        if(j!=0) j=res[j-1];
	        else i++;
	    }
	    if(j==s.size()){
	        pos=i-s.size();
	        break;
	    }
	}
	cout<<pos<<"\n";
	return 0;
}