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
void getNode(Node* head , int &posFromTail,int ans){
    if(head==NULL)
       return;
    getNode(head->next, posFromTail,ans);
    if(posFromTail==0){
        ans=head->data;
    }
    posFromTail--;   
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth= new Node(50);
    
    first->next =second;
    second->next =third;
    third->next =fourth;
    fourth->next =fifth;
    fifth->next =NULL;

    int position=2;
    int ans=-1;
    getNode(first,position,ans);
    // cout<<a;
    

}