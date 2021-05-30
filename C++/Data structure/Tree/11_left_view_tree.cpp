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

// print the node which are visible when you saw tree from left 
//  Example 1
//                 1
//                 \
// person  --->     2     if person saw tree from left the nodes visible is (1,2,7)
//                 / \
//                7   3

// Example 2
//     1
//    / \
//   4   2     ---->   if person saw tree from left the nodes visible is (1,4,7)
//  /     \
// 7       3

void leftView(node* root){
     if(not root)
        return;
    queue<pair<node *,int>> q;
    q.push(make_pair(root,0));
    int c = 0;
    while(!q.empty()){
        pair<node*,int> temp = q.front();
        q.pop();
        if(temp.second==c){
            cout << temp.first->val << " ";
            c+= 1;
        }
        if(temp.first->left)
            q.push(make_pair(temp.first->left,temp.second+1));
        if(temp.first->right)
            q.push(make_pair(temp.first->right,temp.second+1));
    }
}

// preoder
void leftView2(node* root,int &visitedLevel,int currLevel){
    if(not root)
        return;
    if(visitedLevel == currLevel){
        cout << root->val << " ";
        visitedLevel += 1;
    }
     leftView2(root->left,visitedLevel,currLevel+1);
     leftView2(root->right,visitedLevel,currLevel+1);  
   
   
}

int main(){
    node* root = new node(0);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(7);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->right->right = new node(8);
    root->right->right->right->left = new node(9);
    // first approach by level order traversal
    // traverse tree with level order in each level print the element which comes first and skip print the other element of same level
    leftView(root);
    cout << endl;
    // second approach preorder traversal 
    // traverse tree with preorder 
    int c = 0;
    leftView2(root,c,0);
    return 0;
}