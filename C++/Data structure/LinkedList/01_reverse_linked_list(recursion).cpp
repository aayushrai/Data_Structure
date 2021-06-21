#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int val;
    node* next;

    node(int val){
        this->val = val;
        next = NULL;
    }
}node;

void display(node* head){
    node* curr = head;
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

node* reverseLinkedList(node* current){
    if(!current)
        return current;
    if(!current->next)
        return current;
    node* lastNode = reverseLinkedList(current->next);
    current->next->next = current;
    current->next = NULL;
    return lastNode;
}

int main(){
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    display(head);
    head = reverseLinkedList(head);
    display(head);
    
}