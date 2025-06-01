#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }

    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        cout<<"Node with values "<<this->data<<" Deleted"<<endl;


    }
};
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int getLength(Node* head){
    int len=0;
    Node* temp =head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
void insertAtHead(Node* &head, Node* &tail, int data){
    if(head==NULL){
        //ll is empty
        Node* newNode=new Node(data); 
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode =new Node(data);
    newNode->next =head;
    head->prev = newNode;
    head=newNode;
}
void insertAtTail(Node* &head, Node* &tail, int data){
    if(head==NULL){
        //ll is empty
        Node* newNode=new Node(data); 
        head=newNode;
        tail=newNode;
        return;
    }
    Node* newNode =new Node(data);
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}
void insertAtPosition(Node* &head, Node* &tail, int data,int position){
    if(head==NULL){
        //ll is empty
        Node* newNode=new Node(data); 
        head=newNode;
        tail=newNode;
        return;
    } 
    if(position==1){
       //mtlb ki insert at head ho gaya 
       insertAtHead(head,tail,data);
       return;

    }
    int length = getLength(head);
    if(position>length){
        insertAtTail(head,tail,data);
        return;
    }
    //insertion at mid
    //find prev and current 
    int i=1;
    Node* prevNode =head;
    while(i<position-1){
        prevNode=prevNode->next;
        i++;
    }
    Node* curr = prevNode->next;

    Node* newNode = new Node(data);
    prevNode->next =newNode;
    newNode->prev = prevNode ;
    curr->prev =newNode;
    newNode->next = curr ;
 
}
void deleteFromposition(Node* &head, Node* &tail,int position){
    if(head==NULL){
        cout<<"empty";
        return;
    }
    if(head->next ==NULL){
        //single node
        Node* temp =head;
        head= NULL; 
        tail= NULL;
        delete(temp);
        return; 
    }
    
    if(position==1){
        //want to 1st node
        Node* temp =head;
        head = head->next;
        head->prev = NULL;
        temp->next =NULL;
        delete(temp);
        return;

    }
    int len =getLength(head);
    if(position > len){
        cout<<"enter correct position";
    }
    if(position==len){
        //delete last node
        Node* temp = tail;
        tail= tail->prev;
        temp->prev= NULL;
        tail->next = NULL;
        delete temp;
        return;
    }
    //delete from middle 
    //step 1 left right curr
    int i=1;
    Node *left = head;
    while(i<position-1){
        left=left->next;
        i++;
    }
    Node *curr= left->next;
    Node *right =curr->next;
    
    left->next =right ;

    right ->prev= left;

    curr-> prev =NULL;
    curr->next =NULL;
    delete curr;
    return;
}


int main(){
    Node* first =new Node(10);
    Node* second =new Node(20);
    Node* third =new Node(30);

    Node* head= first;
    Node* tail =third;

    first->next = second;
    second->prev =first;

    second->next= third;
    third->prev =second;

    third->next=NULL;

    // print(first);
    // cout<<endl;

    insertAtHead(head,tail,0);
    // print(head);
    // cout<<endl;

    insertAtTail(head,tail,40);
    // print(head);
    // cout<<endl;

    insertAtPosition(head,tail,80,5);
    print(head);
    cout<<endl;

    deleteFromposition(head,tail,1);
    print(head);
    cout<<endl;

    deleteFromposition(head,tail,4);
    print(head);
    cout<<endl;

    deleteFromposition(head,tail,2);
    print(head);
    cout<<endl;

}