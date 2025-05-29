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

    ~Node(){
        cout<<"Node with value:"<<this->data<<"deleted"<<endl;
    }
};

int findLength(Node* &head){
    int length=0;
    Node* temp =head;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}

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

void insertAtPosition(int position,Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node* newNode = new Node(data);
        head=newNode;
        tail=newNode;
        return;
    }

    if(position==0){
        insertAtHead(head,tail,data);
        return;
    }
    int len=findLength(head);
    if(position==len){
        insertAtTail(head,tail,data);
        return;
    }
    //1. find the position : prev and current 
    int i=1;
    Node* prev = head;
    while(i<position){
        prev=prev->next;
        i++;
    }
    Node* current = prev->next;
    //2
    Node* newNode = new Node(data);
    //3
    newNode->next=current;
    //4
    prev->next=newNode;
}
void delteNode(int position,Node* &head, Node* &tail){
    if(head==NULL){
        cout<<"cannot delte , ll is empty";
        return;
    }

    //start node 
    if(position==1){
        Node* temp =head;
        head=head->next;
        temp->next=NULL;
        delete(temp);
        return;
    }
    //end node 
    int len=findLength(head);
    if(position==len){
        //1. find prev
        int i=1;
        Node* prev =head;
        while(i<position-1){
            prev=prev->next;
            i++;
        }
        //2. 
        prev->next =NULL;
        //3.
        Node* temp = tail;
        //4.
        tail=prev;
        //5.
        delete temp;
        return;
    }

    //delting middle 
    int i=1;
    Node* prev =head;
    while(i<position){
        prev =prev->next;
        i++;
    }
    Node* current =prev->next;
    prev->next=current->next;
    current->next=NULL;
    delete(current);

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
    insertAtPosition(0,head,tail,-10);
    insertAtPosition(11,head,tail,50);
    print(head); 
    cout<<endl;
    cout<<"after deltion : "<<endl;
    delteNode(1,head,tail);
    delteNode(11,head,tail);
    delteNode(5,head,tail);

    print(head);  
    return 0;
}