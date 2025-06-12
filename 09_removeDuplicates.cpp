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
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }  
}
void removeDuplicate(Node* &head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return;
    }
    if(head->next==NULL){
        cout<<"Single node"<<endl;
        return;
    }
    Node* curr =head;

    while(curr!=NULL){
        if((curr->next!=NULL) && (curr->data == curr->next->data)){
            //equal
            Node* temp = curr->next; //for deleting the node 
            curr->next = curr->next->next;
            //delete node
            temp->next=NULL;
            delete temp;
        }
        else{//not equal
            curr=curr->next;
        } 
    }
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(20);
    Node* fourth = new Node(30);
    Node* fifth = new Node(40);
    Node* sixth = new Node(40);
    
    head->next =second;
    second->next =third;
    third->next =fourth; 
    fourth->next =fifth;
    fifth->next =sixth;
    sixth->next =NULL;

    print(head);
    cout<<endl;

    removeDuplicate(head);
    print(head);
    

}