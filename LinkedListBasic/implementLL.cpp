#include <bits/stdc++.h>

using namespace std;

class node{
public:

    int data;
    node * next;

    node(int data){ 
       this->data=data;
        next=NULL;
    }
};

void insertBegin(node * &head,int x){

    if(head==NULL){
        head = new node(x);
        return;
    }

    node *n= new node(x);
    n->next=head;
    head=n;
    return;


}

void insertEnd(node * &head,int val){
    node *last = new node(val);
    node *curr=head;
    if(head==NULL){
        head=last;
        return;
    }
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=last;
    return;
}

void printLL(node * head){
    if(head==NULL){
        cout<<"LL is NULL"<<endl;
        return;
    }
    
    while(head!=NULL){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<endl;
}

void insertAfter(node * prev,int val){
    if(prev==NULL){
        cout<<"No value found";
        return;
    }

    node *n = new node(val);

    if(prev->next==NULL){
        prev->next=n;
        return;
    }
    
    n->next=prev->next;
    prev->next=n;
}


int main(){

    node *head = NULL;
    // insertBegin(head,20);
    // insertBegin(head,2);
    // insertBegin(head,30);
    // insertBegin(head,40);
    // insertBegin(head,24);
    // insertBegin(head,30);
    insertEnd(head,55);
    // insertBegin(head,40);
    // insertBegin(head,24);
    // insertBegin(head,30);
    insertAfter(head,20);
    insertAfter(head->next,21);


    printLL(head);
   
    return 0;


}