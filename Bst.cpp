#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

Node *insert(Node *root,int data){
    if(root==nullptr) return new Node(data);
    if(root->data>data) root->left=insert(root->left,data);
    else root->right=insert(root->right,data);
    return root;
}

void inorder(Node *root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node *searchInBst(Node *root,int key){
    if(root==nullptr) return nullptr;
    if(root->data==key) return root;
    if(root->data>key) return searchInBst(root->left,key);
    else return searchInBst(root->right,key);
}

Node *inorderSuccessor(Node *root){
    if(root==nullptr) return nullptr;
    Node *current=root;
    while(current and current->left!=nullptr) current=current->left;
    return current;
}

Node *deleteInBst(Node *root,int key){
    if(root==nullptr) return nullptr;
    if(key<root->data) root->left=deleteInBst(root->left,key);
    else if(key>root->data) root->right=deleteInBst(root->right,key);
    else {
        if(root->left==nullptr){
            Node *temp=root->right;
            free(root);
            return temp;
        }else if(root->right==nullptr){
            Node *temp=root->left;
            free(root);
            return temp;
        }else{
            Node *temp=inorderSuccessor(root->right);
            root->data=temp->data;
            root->right=deleteInBst(root->right,temp->data);
        }
        return root;
    }
}

Node *constructBst(int preorder[],int *preorderIdx,int key,int min,int max,int n){
    if(*preorderIdx>=n) return NULL;
    Node *root=NULL;
    if(min<key and key<max){
        root=new Node(key);
        *preorderIdx=*preorderIdx+1;
        if(*preorderIdx<n){
            root->left=constructBst(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n){
            root->right=constructBst(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;
}

bool isBst(Node *root,Node *min=NULL,Node *max=NULL){
    if(root==NULL) return 1;
    if(min!=NULL and root->data<=min->data) return 0;
    if(max!=NULL and root->data>=max->data) return 0;
    bool leftValid=isBst(root->left,min,root);
    bool rightValid=isBst(root->right,root,max);
    return leftValid and rightValid;
}

Node *sortedArrayToBst(int a[], int start,int end){
    if(start>end) return NULL;
    int mid=start+(end-start)/2;
    Node *root=new Node(a[mid]);
    root->left=sortedArrayToBst(a,start,mid-1);
    root->right=sortedArrayToBst(a,mid+1,end);
    return root;
}

int catalan(int n){
    if(n<=1) return 1;
    int res=0;
    for(int i=0;i<n;++i){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}

vector<Node*> constructTrees(int start,int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;++i){
        vector<Node*> leftSubtree=constructTrees(start,i-1);
        vector<Node*> rightSubtree=constructTrees(i+1,end);
        for(int j=0;j<leftSubtree.size();++j){
            Node *left=leftSubtree[j];
            for(int k=0;k<rightSubtree.size();++k){
                Node *right=rightSubtree[k];
                Node *node=new Node(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
        }
    }
    
    return trees;
}

void preorder(Node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void zigzagTraversal(Node *root){
    if(root==NULL) return;
    stack<Node*> currentLevel;
    stack<Node*> nextLevel;
    bool leftToRight=1;
    currentLevel.push(root);
    while(!currentLevel.empty()){
        Node *temp=currentLevel.top();
        currentLevel.pop();
        if(temp){
            cout<<temp->data<<" ";
            if(leftToRight){
                if(temp->left) nextLevel.push(temp->left);
                if(temp->right) nextLevel.push(temp->right);
            }else{
                if(temp->right) nextLevel.push(temp->right);
                if(temp->left) nextLevel.push(temp->left);
            }
            if(currentLevel.empty()){
                leftToRight=!leftToRight;
                swap(currentLevel,nextLevel);
            }
        }
    }
}

bool isIdentical(Node *root1,Node *root2){
    if(root1==NULL and root2==NULL) return 1;
    else if(root1==NULL or root2==NULL) return 0;
    else{
        bool cond1=(root1->data==root2->data);
        bool cond2=isIdentical(root1->left,root2->left);
        bool cond3=isIdentical(root1->right,root2->right);
        if(cond1 and cond2 and cond3) return 1;
        return 0;
    }
}

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBst;
};

Info largestBstInBt(Node *root){
    if(root==NULL) return {0,INT_MIN,INT_MAX,0,false};
    if(root->left==NULL and root->right==NULL) return {1,root->data,root->data,1,true};
    Info leftInfo=largestBstInBt(root->left);
    Info rightInfo=largestBstInBt(root->right);
    Info current;
    current.size=(1+leftInfo.size+rightInfo.size);
    if(leftInfo.isBst and rightInfo.isBst and leftInfo.max<root->data and rightInfo.min>root->data){
        current.min=min(leftInfo.min,min(rightInfo.min,root->data));
        current.max=max(rightInfo.max,max(leftInfo.max,root->data));
        current.ans=current.size;
        current.isBst=true;
        return current;
    }
    current.ans=max(rightInfo.ans,leftInfo.ans);
    current.isBst=false;
    return current;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void calcPointers(Node *root,Node **first,Node **mid,Node **last,Node **prev){
    if(root==NULL) return;
    calcPointers(root->left,first,mid,last,prev);
    if(*prev and root->data<(*prev)->data){
        if(!*first){
            *first=*prev;
            *mid=root;
        }else *last=root;
    }
    *prev=root;
    calcPointers(root->right,first,mid,last,prev);
}

void restoreBst(Node *root){
    Node *first=NULL,*mid=NULL,*last=NULL,*prev=NULL;
    calcPointers(root,&first,&mid,&last,&prev);
    if(first and last) swap(&(first->data),&(last->data));
    else if(first and mid) swap(&(first->data),&(mid->data));
}

void inorder(Node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    Node *root=new Node(6);
    root->left=new Node(9);
    root->right=new Node(3);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->right=new Node(13);
    inorder(root);
    cout<<"\n";
    restoreBst(root);
    inorder(root);
    cout<<"\n";
	return 0;
}