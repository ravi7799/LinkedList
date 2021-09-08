#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void insertAtFirstCLL(Node* &head,int item){
    Node* ptr=new Node;
    ptr->data=item;
    ptr->next=NULL;

    if(head==NULL){
        head=ptr;
        ptr->next=head;
    }else{
        ptr->next=head;
        head=ptr;
        Node* temp=head->next;

        while(temp->next != head->next){
            temp=temp->next;
        }
        temp->next=head;
    }
}

void insertAtLastCLL(Node* &head,int item){
    Node* ptr=new Node;
    ptr->data=item;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        ptr->next=head;
    }else{
        Node* temp=head;
        while(temp->next != head){
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=head;
    }
}

void printCLL(Node* head){
    if(head==NULL){
        cout<<"Circular Linked list is Empty\n";
    }else{
        Node* temp=head;
        while(temp->next != head){
            cout<<temp->data<<" -- >";
            temp=temp->next;
        }
        cout<<temp->data<<" ";
    }
}

int main(){
    Node* head=NULL;
    int n;
    cout<<"Enter the Number of Nodes you want to insert in the Circular Linekd list\n";
    cin>>n;

    for(int i=0;i<n;i++){
        int item;
        cin>>item;
        insertAtFirstCLL(head,item);
        printCLL(head);
    }

    return 0;
}