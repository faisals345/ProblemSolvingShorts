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


int main(){

    node *head = NULL;
    insertBegin(head,20);
    insertBegin(head,2);
    insertBegin(head,30);
    insertBegin(head,40);
    insertBegin(head,24);
    insertBegin(head,30);


    printLL(head);
   
    return 0;


}