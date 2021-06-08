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

node * findMiddle(node *head){

    node *slow,*fast;
    slow=head;
    fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast==NULL){
        return slow;
    }else{
        return slow->next;
    }
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
void reverseLL(node *&head){

    if(head==NULL || head->next==NULL){
        return;
    }

    node *prev = NULL;
    node * curr=head;
    node * curr_nxt = head;

    while(curr!=NULL){
        curr_nxt=curr_nxt->next;
        curr->next=prev;
        prev=curr;
        curr=curr_nxt;
    }
    head=prev;
    
}
bool isPalindrome(node *head){
    // slow and fast

    node * slow = findMiddle(head);
    reverseLL(slow);
    node * fast = head;
    while(slow!=NULL){
        if(slow->data!=fast->data){
            return false;
        }
        fast=fast->next;
        slow=slow->next;
    }
    return true;


}

node* mergeSorted(node *head1,node * head2){

    node *res = NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data > head2->data){
            insertBegin(res,head2->data);
            head2=head2->next;
        }else{
                insertBegin(res,head1->data);
                head1=head1->next;

        }
    }
    while(head1!=NULL){
         insertBegin(res,head1->data);
          head1=head1->next;

    }
    while(head2!=NULL){
          insertBegin(res,head2->data);
          head2=head2->next;

    }
    printLL(res);
    return res;






}




int main(){
    node * head = NULL;
    insertBegin(head,1);
    insertEnd(head,2);
    insertEnd(head,3);
    insertEnd(head,2);
    insertEnd(head,1);
    insertEnd(head,1);
   bool t= isPalindrome(head);
   cout<<t<<endl;

    

   
   
    return 0;


}