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

void zigzag(node* root)
{
    if(not root)
        return;
    stack<node*> s1,s2;
    s1.push(root);
    while(!s1.empty() or !s2.empty())
    {
        while(!s1.empty()){
            node* temp = s1.top();
            cout << temp->val;
            s1.pop();
            if(temp->right)
                s2.push(temp->right);
            if(temp->left)
                s2.push(temp->left);  
        }
        while(!s2.empty()){
            node* temp = s2.top();
            cout << temp->val;
            s2.pop();
            if(temp->left)
                s1.push(temp->left);
            if(temp->right)
                s1.push(temp->right);
        }
    }
}

int main(){
    node* root = new node(5);
    root->left = new node(7);
    root->right = new node(9);
    root->left->left = new node(0);
    root->left->right = new node(1);
    root->right->left = new node(4);
    zigzag(root);
    return 0;
}

