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
Node* reverse(Node* prev, Node* curr){
    //bs 
    if(curr==NULL){
        //ki LL reverse ho gaya hai
        return prev;
    }  
    Node* frwd = curr->next;
    curr->next =prev;

    // reverse(prev->next,curr->next);
    reverse(curr,frwd);

}
Node* reverseLoop(Node* head){
    Node* prev = NULL;
    Node* curr =head;

    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev =curr;
        curr=temp;
    }
    return prev;   
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

    print(first); 
    cout<<endl;


    Node* head = first;


    Node* prev =NULL;
    Node* curr = head;
    // head = reverse(prev,curr);
    head=reverseLoop(head);
    cout<<"reverse: "<<endl;
    print(head);
    return 0;
}