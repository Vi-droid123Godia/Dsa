#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    
    node(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

void preorder(struct node *root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(struct node *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;++i) if(inorder[i]==curr) return i;
    return -1;
}

node *buildTree(int preorder[],int inorder[],int start,int end){
    static int idx=0;
    if(start>end) return nullptr;
    int curr=preorder[idx++];
    node *newnode=new node(curr);
    if(start==end) return newnode;
    int pos=search(inorder,start,end,curr);
    newnode->left=buildTree(preorder,inorder,start,pos-1);
    newnode->right=buildTree(preorder,inorder,pos+1,end);
    return newnode;
}

node *buildtree(int postorder[],int inorder[],int start,int end){
    static int idx=4;
    if(start>end) return nullptr;
    int curr=postorder[idx--];
    node *newnode=new node(curr);
    if(start==end) return newnode;
    int pos=search(inorder,start,end,curr);
    newnode->right=buildtree(postorder,inorder,pos+1,end);
    newnode->left=buildtree(postorder,inorder,start,pos-1);
    return newnode;
}

void levelOrderTraversal(node *root){
    if(!root) return;
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        node *n=q.front();
        q.pop();
        if(n){
            cout<<n->data<<" ";
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }else if(!q.empty()) q.push(nullptr);
    }
}

int kthsum(node *root,int k){
    if(!root) return -1;
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    int level=0;
    int sum=0;
    while(!q.empty()){
        node *n=q.front();
        q.pop();
        if(n){
            if(level==k) sum+=n->data;
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }else if(!q.empty()) {
            q.push(nullptr); 
            level++;
        }
    }
    return sum;
}

int countNodes(node *root){
    if(!root) return 0;
    return countNodes(root->left) + countNodes(root->right) +1;
}

int sumNodes(node *root){
    if(!root) return 0;
    return sumNodes(root->left)+sumNodes(root->right)+root->data;
}

int calcHeight(node *root){
    if(!root) return 0;
    int leftHeight=calcHeight(root->left);
    int rightHeight=calcHeight(root->right);
    return max(leftHeight,rightHeight)+1;
}

int diameter(node *root){
    if(!root) return 0;
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    int currdiameter=lHeight+rHeight+1;
    int lDiameter=diameter(root->left);
    int rDiameter=diameter(root->right);
    return max(currdiameter,max(lDiameter,rDiameter));
}

int calcDiameter(node *root,int *height){
    if(!root){
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int lDiameter=calcDiameter(root->left,&lh);
    int rDiameter=calcDiameter(root->right,&rh);
    int currDiameter=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currDiameter,max(lDiameter,rDiameter));
}

void sumReplace(node *root){
    if(!root) return;
    sumReplace(root->left);
    sumReplace(root->right);
    if(root->left) root->data+=root->left->data;
    if(root->right) root->data+=root->right->data;
}

bool isBalanced(node *root){
    if(!root) return true;
    if(!isBalanced(root->left)) return 0;
    if(!isBalanced(root->right)) return 0;
    int lh=calcHeight(root->left);
    int rh=calcHeight(root->right);
    if(abs(lh-rh)<=1) return 1;
    else return 0;
}

bool isBalanced(node *root,int *height){
    if(!root) return 1;
    int lh=0,rh=0;
    if(!isBalanced(root->left,&lh)) return 0;
    if(!isBalanced(root->right,&rh)) return 0;
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1) return 1;
    else return 0;
}

void rightView(node *root){
    if(!root) return;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;++i){
            node *curr=q.front();
            q.pop();
            if(i==n-1) cout<<curr->data<<" ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        
    }
}

void leftView(node *root){
    if(!root) return;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=1;i<=n;++i){
            node *temp=q.front();
            q.pop();
            if(i==1) cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

// node *Lca(node *root,int n1,int n2){
//     if(!root) return nullptr;
//     if(root->data==n1 or root->data==n2) return root;
//     node *left=Lca(root->left,n1,n2);
//     node *right=Lca(root->right,n1,n2);
//     if(left!=nullptr and right!=nullptr) return root;
//     if(left==nullptr and right==nullptr) return nullptr;
//     if(left!=nullptr) return Lca(root->left,n1,n2);
//     return Lca(root->right,n1,n2);
// }

int findDistance(node *root,int k,int d){
    if(root==nullptr) return -1;
    if(root->data==k) return d;
    int left=findDistance(root->left,k,d+1);
    if(left!=-1) return left;
    return findDistance(root->right,k,d+1);
}

int distanceBtwNodes(node *root,int n1,int n2){
    node *lca=Lca(root,n1,n2);
    int d1=findDistance(lca,n1,0);
    int d2=findDistance(lca,n2,0);
    return d1+d2;
}

void flatten(node *root){
    if(root==nullptr or (root->left==nullptr and root->right==nullptr)) return;
    if(root->left!=nullptr){
        flatten(root->left);
        node *temp=root->right;
        root->right=root->left;
        root->left=nullptr;
        node *t=root->right;
        while(t->right!=nullptr) t=t->right;
        t->right=temp;
    }
    flatten(root->right);
}

void printSubtreeNodes(node *root,int k){
    if(root==nullptr or k<0) return;
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

int printNodesAtk(node *root,node *target,int k){
    if(root==nullptr) return -1;
    if(root==target){
        printSubtreeNodes(root,k);
        return 0;
    }
    int dl=printNodesAtk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k) cout<<root->data<<" ";
        else printSubtreeNodes(root->right,k-dl-2);
        return 1+dl;
    }
    int dr=printNodesAtk(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k) cout<<root->data<<" ";
        else printSubtreeNodes(root->left,k-dr-2);
        return 1+dr;
    }
    return -1;
}

bool getPath(node *root,int key,vector<int> &path){
    if(root==nullptr) return false;
    path.push_back(root->data);
    if(root->data==key) return 1;
    if(getPath(root->left,key,path) or getPath(root->right,key,path)) return 1;
    path.pop_back();
    return 0;
}

int Lca(node *root,int n1,int n2){
    vector<int> path1,path2;
    if(!getPath(root,n1,path1) or !getPath(root,n2,path2)) return -1;
    int pc=0;
    for(pc=0;pc<path1.size() and path2.size();++pc) if(path1[pc]!=path2[pc]) break;
    return path1[pc-1];
}

node *Lca(node *root,int n1,int n2){
    if(root==nullptr) return nullptr;
    if(root->data==n1 or root->data==n2) return root;
    node *left=Lca(root->left,n1,n2);
    node *right=Lca(root->right,n1,n2);
    if(left and right) return root;
    if(!left and !right) return nullptr;
    if(left) return left;
    return right;
}

int maxSumPathUtil(node *root,int &ans){
    if(root==nullptr) return 0;
    int left=maxSumPathUtil(root->left,ans);
    int right=maxSumPathUtil(root->right,ans);
    int nodeMax=max(max(root->data,root->data+left+right),max(root->data+left,root->data+right));
    ans=max(ans,nodeMax);
    int singlePathSum=max(root->data,max(root->data+left,root->data+right));
    return singlePathSum;
}

int maxSumPath(node *root){
    int ans=INT_MIN;
    maxSumPathUtil(root,ans);
    return ans;
}

int main() {
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->right=new node(5);
    cout<<maxSumPath(root);
    cout<<"\n";
	return 0;
}