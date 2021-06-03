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



void kthNodes(node* root,int k,unordered_map<node*,node*>&mp){
    queue<pair<node*,int>> q;
    q.push(make_pair(root,k));
    unordered_map<node*,bool>visit;
    while(!q.empty()){
        pair<node*,int>temp = q.front();
         q.pop();
        visit[temp.first] = true;
        if(temp.second==0){
            cout << temp.first->val << " ";
        }
        if(temp.first->left and !visit[temp.first->left])
            q.push(make_pair(temp.first->left,temp.second-1));
        if(temp.first->right and !visit[temp.first->right])
            q.push(make_pair(temp.first->right,temp.second-1));
        if(mp[temp.first] and !visit[mp[temp.first]]){
            q.push(make_pair(mp[temp.first],temp.second-1));
        }
    }
                
}
void findTargetNode(node* root,int target,int k,unordered_map<node*,node*>&mp){
    if(not root)
        return;
    if(root->val ==target)
        kthNodes(root,k,mp);
    findTargetNode(root->left,target,k,mp);
    findTargetNode(root->right,target,k,mp);
}
void ParentNodes(node* root,node * parent,unordered_map<node*,node*>&mp){
    if(not root)
        return;
    mp[root] = parent;
    ParentNodes(root->left,root,mp);
    ParentNodes(root->right,root,mp);
    
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->right = new node(3);
    root->left->right->left = new node(4);
    root->right->left = new node(8);
    root->right->left->left = new node(10);
    root->right->right = new node(6);
    root->right->right->left = new node(7);
    root->right->right->left->left = new node(9);
    int k = 2;
    int target = 5;
    unordered_map<node*,node*> mp;
    ParentNodes(root,NULL,mp);
    findTargetNode(root,target,k,mp);
    return 0;
}

//     1
//   /   \
//  2     5 <- target node , from target node find all the kth node
//   \   / \
//    3 8   6   
//   / /   /
//  4 10  7
//       /
//      9


// Aproach

// # simple words
//first we find target node
// then we apply bfs from target node (left,right and parent)

// # coding words

//first we find parent of all the node and store it into map (because we need parent node in order to find kth node)
//Then we going to find target node using any approach bfs(level order),dfs(preorder,inorder,postorder)
//After this we apply bfs for find kth node ,this is not simple bfs because we also need to apply bfs child to parent direction in this we use 
//our map that we created in first step and we also track visited node because when we apply bfs on parent its going to again visite the child node that already visited
