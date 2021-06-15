#include<iostream>

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

node* LCA(node* root,int d1,int d2){
    if(!root)
        return NULL;

    if(root->val == d1 || root->val== d2){
        return root;
    }
    node* leftLca  = LCA(root->left,d1,d2);
    node* rightLca = LCA(root->right,d1,d2);

    if(leftLca && rightLca) return root;
    if(leftLca) return leftLca;
    if(rightLca) return rightLca;
    return NULL;
}
int main(){
    node* root = new node(0);
    root->left = new node(1);
    root->left->left = new node(3);
    root->right = new node(2);
    root->right->left = new node(4);
    root->right->right = new node(5);
    node* temp = LCA(root,1,5);
    cout << temp->val << endl;
    }




