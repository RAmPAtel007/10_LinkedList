#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data= data;
        this->next= NULL;
    }
};
void print(Node* &head){
    Node* temp =head ; 
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* getMiddle(Node* &head){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return head;
    }
    if(head->next == NULL){
        //ek he node hai 
        return head;
    }

    Node* slow =head;
    Node* fast = head; // acc to head->next bhi kr skte hai 

    while(slow!=NULL && fast != NULL){
        fast=fast->next; // 1 step aage badhaya hai q ki agar last node per ho toh null ka next per null pointer exception aa jayega 
        if(fast!=NULL){
            fast=fast->next; //temaing 1 step of fast 
            slow=slow->next;
        }
    }
    return slow;
}

int main(){
    Node* head =new Node(10);
    Node* second =new Node(20);
    Node* third =new Node(30);
    Node* fourth =new Node(40);
    Node* fifth =new Node(50);

    head->next = second;
    second->next =third;
    third->next =fourth;
    fourth->next =fifth;
    fifth-> next =NULL;

    print(head);
    cout<<endl;
    cout<<"Middle node is : "<< getMiddle(head)->data <<endl;

}