#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> minheap;
priority_queue<int,vector<int>> maxheap;

void insert(int x){
    if(minheap.size()==maxheap.size()){
        if(maxheap.size()==0){
            maxheap.push(x);
            return;
        }
        if(x<maxheap.top()) maxheap.push(x);
        else minheap.push(x);
    }else{
        if(maxheap.size()>minheap.size()){
            if(x>=maxheap.top()){
                minheap.push(x);
            }else{
                int temp=maxheap.top();
                maxheap.pop();
                minheap.push(temp);
                maxheap.push(x);
            }
        }else{
            if(x<=minheap.top()){
                minheap.push(x);
            }else{
                int temp=minheap.top();
                minheap.pop();
                maxheap.push(temp);
                minheap.push(x);
            }
        }
    }
}

double findMedian(){
    if(minheap.size()==maxheap.size()) return ((minheap.top()+maxheap.top())/2.0);
    else if(maxheap.size()>minheap.size()) return maxheap.top();
    else return minheap.top();
}

int main() {
	insert(10);
	cout<<findMedian()<<"\n";
	insert(15);
	cout<<findMedian()<<"\n";
	insert(21);
	cout<<findMedian()<<"\n";
	insert(30);
	cout<<findMedian()<<"\n";
	insert(18);
	cout<<findMedian()<<"\n";
	insert(19);
	cout<<findMedian()<<"\n";
	return 0;
}