#include<iostream>
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


int sumTree(node* root){
    if(!root)
        return 0;
    if(!root->left and !root->right){
        int temp =  root->val;
        root->val =0 ;
        return temp;
    }
    int left = sumTree(root->left);
    int right = sumTree(root->right);

    int temp = root->val;
    root->val = left+right;
    return left+right+temp;
}

void display(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        cout << temp->val << " ";
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}
int main(){
    node* root = new node(20);
    root->left = new node(3);
    root->right = new node(7);
    root->right->left = new node(3);
    root->right->right = new node(4);
    root->left->left = new node(2);
    root->left->right = new node(1);
    sumTree(root);
    display(root);

    return 0;
}


  /*   sum tree
         20 (1+2+3+4+3+7)
       /   \  
(1+2) 3     7  (4+3) 
    / \     / \  
   1   2   4   3 
    */