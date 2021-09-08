#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void insertAtLastDLL(Node* &head,int item){
    Node* ptr=new Node;
    ptr->data=item;
    ptr->next=NULL;
    ptr->prev=NULL; //1st extra line 

    if(head==NULL){
        head=ptr;
    }else{
        Node* temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->prev=temp;
    }
}

void  printDLL(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<" --> ";
        temp=temp->next;
    }
    cout<<"\n";
}

void printRDLL(Node* head){
    Node* temp=head;
    while(temp->next != NULL){
        temp=temp->next;
    }

    while(temp != NULL){
        cout<<temp->data<<" , ";
        temp=temp->prev;
    }
    cout<<"\n";
}

int main(){
    Node* head=NULL;
    int n;
    cout<<"Enter the Number of Nodes you want to insert in the Circular Linekd list\n";
    cin>>n;

    for(int i=0;i<n;i++){
        int item;
        cin>>item;
        insertAtLastDLL(head,item);
        printDLL(head);
        printRDLL(head);
    }

    return 0;
}