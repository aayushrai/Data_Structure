#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int val;
    node* left;
    node* right;

    node(int val){
        this->val = val;
        left = right = NULL;
    }
}node;

node* LCA(node* root,int a,int b,bool &flag){
    if(not root)
        return NULL;
    if(root->val == a or root->val == b)
        return root;
    node* leftLca = LCA(root->left,a,b,flag);
    node* rightLca = LCA(root->right,a,b,flag);
    if(leftLca and rightLca){
        flag = false;
        return root;
    }
    if(leftLca)
        return leftLca;
    if(rightLca)
        return rightLca;
    return NULL;
}

bool samePath(node* root,int n1,int n2){
    bool flag = true;
    LCA(root,n1,n2,flag);
    return flag;
}

int main(){
    node* root = new node(0);
    root->left = new node(1);
    root->left->left = new node(3);
    root->left->right = new node(7);
    root->right = new node(2);
    root->right->left = new node(4);
    root->right->right = new node(5);
    cout << samePath(root,1,7) << endl;
}