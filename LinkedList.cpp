#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertAtLast(Node* &head,int item){
    Node* ptr=new Node;
    ptr->data=item;
    ptr->next=NULL;

    if(head==NULL){
        head=ptr;
    }else{
        Node* temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=ptr;
    }
}

void insertAtHead(Node* &head,int item){
    Node* ptr=new Node;
    ptr->data=item;
    ptr->next=NULL;

    if(head==NULL){
        head=ptr;
    }else{
        ptr->next=head;
        head=ptr;
    }
}

void insertAtK(Node* &head,int item,int k){
    if(k==1){
        insertAtHead(head,item);
    }else{
        Node* ptr=new Node;
        ptr->data=item;
        ptr->next=NULL;

        Node* temp=head;
        for(int i=1;i<=k-2;i++){
            temp=temp->next;
        }

        Node* x=temp->next;
        temp->next=ptr;
        ptr->next=x;
    }
}


void PrintLL(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" --> ";
        temp=temp->next;
    }
    cout<<"\n";
}


void deleteFirst(Node* &head){
    if(head==NULL){
        cout<<"There is no element in the Linked List.\n";
    }else if(head->next==NULL){
        delete(head);
        head=NULL;
    }else{
        Node* temp=head;
        head=head->next;
        delete(temp);
    }
}

void deleteLast(Node* &head){
    if(head==NULL){
        cout<<"There is no element in the Linked List.\n";
    }else if(head->next==NULL){
        delete(head);
        head=NULL;
    }else{
        Node* temp=head;
        while(temp->next->next != NULL){
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=NULL;
    }
}

int main(){
    Node* head=NULL;
    cout<<"how many items you want to insert:\n";
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int item;
        cin>>item;
        insertAtLast(head,item);
        //printing a linked list.
        PrintLL(head);
    }
    
    deleteFirst(head);
    PrintLL(head);
    deleteFirst(head);
    PrintLL(head);
    deleteFirst(head);
    PrintLL(head);

    return 0;
}