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
bool checkForLoop(Node* head){
    if(head==NULL){
        return false;//empty
    }
    if(head->next==NULL){
        return false;
    }
    Node* fast=head;
    Node* slow=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==slow){
            return true; //cycle found
        }
    }
    return false;
}
Node* startingPointLoop(Node* head){
    if(head==NULL){
        return NULL;//empty
    }
    if(head->next==NULL){
        return NULL;
    }
    Node* fast=head;
    Node* slow=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==slow){
            slow=head;
            break;
        }
    }
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow; //or fast

}
Node* removeLoop(Node* head){
    if(head==NULL){
        return NULL;//empty
    }
    // if(head->next==NULL){
    //     return NULL;
    // }
    Node* fast=head;
    Node* slow=head;

    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==slow){
            slow=head;
            break;
        }
    }
    Node* prev = fast;
    while(slow!=fast){
        prev=fast;
        slow=slow->next;
        fast=fast->next;
    }
    prev->next =NULL;
    return slow; //or fast

}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth= new Node(50);
    Node* sixth= new Node(60);
    Node* seventh= new Node(70);
    Node* eighth= new Node(80);
    Node* ninth= new Node(90);
    
    first->next =second;
    second->next =third;
    third->next =fourth;
    fourth->next =fifth;
    fifth->next =sixth;
    sixth->next =seventh;
    seventh->next =eighth;
    eighth->next =ninth;
    ninth->next =fourth;
    Node* head=first;

    //1 is true 
    //0 is false

    cout<<"LOOP is present or not "<< checkForLoop(head)<<endl;
    cout<<"starting loop point is at "<<startingPointLoop(head)->data<<endl;
    removeLoop(head);
    print(head);
    cout<<endl;
    cout<<"loop is" << checkForLoop(head);
}