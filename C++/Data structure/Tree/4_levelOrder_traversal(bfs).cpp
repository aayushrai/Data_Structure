#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
   int val;
   node* left;
   node* right;
   node(int key){
    val = key;
    left = NULL;
    right = NULL;
}

}node;

void levelOrder_and_Bfs(node* root){
    if(!root)
        return;
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        cout << temp->val <<" ";
        q.pop();
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

int main(){
    node* root =new node(1);
    root->left =new node(2);
    root->right =new node(3);
    root->right->left =new node(6);
    levelOrder_and_Bfs(root);
}
