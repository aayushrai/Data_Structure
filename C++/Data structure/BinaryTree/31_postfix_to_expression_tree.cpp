#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    char val;
    node *left,*right;

    node(char val){
        this->val = val;
        left = right =NULL;
    }
}node;

void inorder(node* root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

node* postfix_to_expression_tree(string postfix,int& i){
    if(i<0)
        return NULL;
    node* nw = new node(postfix[i]);
    i--;
    string op = "+-*/";
    if(op.find(postfix[i+1])<=postfix.length()){
        nw->right = postfix_to_expression_tree(postfix,i);
        nw->left = postfix_to_expression_tree(postfix,i);
        
    }
    return nw;
}

int main(){
    string postfix = "45+93-*";
    int i= postfix.length()-1;
    node* root = postfix_to_expression_tree(postfix,i);
    inorder(root);
}