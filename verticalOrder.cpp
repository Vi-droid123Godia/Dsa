#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *left,*right;
};

Node* newNode(int data){
    Node *node=new Node;
    node->data=data;
    node->left=node->right=NULL;
}

void verticalOrder(Node *root,int hdis,map<int,vector<int>> &m){
    if(root==NULL) return;
    m[hdis].push_back(root->data);
    verticalOrder(root->left,hdis-1,m);
    verticalOrder(root->right,hdis+1,m);
}

int main() {
    Node *root=newNode(10);
    root->left=newNode(7);
    root->right=newNode(4);
    root->left->left=newNode(3);
    root->left->right=newNode(11);
    root->right->left=newNode(14);
    root->right->right=newNode(6);
    map<int,vector<int>> m;
    verticalOrder(root,0,m);
    for(auto e:m){
        for(int i=0;i<(e.second).size();++i){
            cout<<e.second[i]<<" ";
        }
        cout<<"\n";
    }
	return 0;
}