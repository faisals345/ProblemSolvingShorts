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

void printMiddleFast(node *head){
    
    node *slow=head;
    node *fast = head;

    if(head!=NULL){
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        cout<<slow->data<<endl;
    }
    return;
 
  
}


int main(){

    node *head = NULL;
    insertBegin(head,20);
    insertEnd(head,21);
    insertEnd(head,22);
     insertEnd(head,28);
    insertEnd(head,22);
    insertEnd(head,22);
    
    printLL(head);
    printMiddleFast(head);
    //20-->21-->22-->21-->22-->22-->
      //22 21
  
   

   
   
    return 0;


}