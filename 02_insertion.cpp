#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data=0;
        this->next=NULL;
    }

    Node(int data){
        this->data =data;
        this->next =NULL;
        
    }
};

void insertAtHead(Node* &head ,Node* &tail, int data){

    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }
    //1. create a node 
    Node* newNode = new Node(data);
    //2. 
    newNode-> next = head;

    // if(head==NULL){//means 1st node 
    //     tail=newNode; //there is no issue in code this if is only to update the tail pointer 
    // }
    //3.
    head = newNode;
}
void insertAtTail(Node* &head ,Node* &tail, int data){
     if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    Node* newNode =new Node(data);

    // if(tail==NULL){ //alag se handle kr lo bhai esko agr list he empty hai toh tail->next bhi null he hoga 
    //     //first node ab add hone wali hai 
    //     tail=newNode;
    //     head=newNode;
    // }
    // else
        
        tail->next = newNode;

    tail=newNode;

}
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main(){
    // Node* head = new Node(10);
    //its not important that head have data it may have the null
    Node* head =NULL; 
    Node* tail=NULL;
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);
    insertAtTail(head,tail,0);
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);

    print(head);  
    return 0;
}