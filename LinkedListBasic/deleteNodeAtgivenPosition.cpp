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

void deleteNodeAtGivenPosition(node * &head,int val){

    if(head==NULL){
        return;
    }
  
  node *temp=head;
  node *prev=NULL;

    int size=0;
    node * curr=head;
    while(curr!=NULL){
        size++;
        curr=curr->next;
    }

    if(val>=size){
        return;
    }

    if(val==0 && head->next==NULL){
        head=NULL;
        delete temp;
        return;
    }

    int i=0;

    while(i<val){
        i++;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    delete temp;
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
    insertBegin(head,20);
    // insertEnd(head,21);
    // insertEnd(head,22);
    // insertEnd(head,23);
    // insertEnd(head,24);
    // insertEnd(head,25);
    printLL(head);
    //20-->21-->22-->23-->24-->25-->
    deleteNodeAtGivenPosition(head,0);
    printLL(head);
   

   
   
    return 0;


}