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
int getLength(Node* &head){
    int i=0;
    Node* temp =head;
    while(temp!= NULL){
        temp =temp->next;
        i++;
    }
    return i;
}
Node* reverseKNodes(Node* &head ,int k){
    if(head==NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
    }
    int len = getLength(head);
    if(k>len){
        // cout<<"Enter valid value for k"<<endl;
        return head;
    }
    //step 1 reverse first k nodes of ll
    Node* prev = NULL;
    Node* curr = head;
    Node* frwd = curr->next;
    int count=0;

    while(count <k){
        frwd = curr ->next;
        curr ->next =prev;
        prev=curr;
        curr =frwd;
        count++;
        
    }
    // step 2
    if(frwd !=NULL){
        //mtlb ki aage nodes baki hai 
        Node* recurssionKaAns= reverseKNodes(frwd,k);
        head->next = recurssionKaAns;
    }

    // step 3
    return prev ; //check copy if you unable to understand the return 

}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth= new Node(50);
    Node* sixth= new Node(60);
    
    first->next =second;
    second->next =third;
    third->next =fourth;
    fourth->next =fifth;
    fifth->next =sixth;
    sixth->next =NULL;

    Node* head= first;

    print(head);
    cout<<endl;
    head = reverseKNodes(head,4);
    print(head);
    

}