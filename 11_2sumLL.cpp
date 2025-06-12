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
Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr = head;
    Node* frwd = curr->next;

    while(curr!=NULL){
        frwd = curr->next;
        curr ->next =prev;
        prev=curr;
        curr=frwd;
    }
    return prev;

}
Node* solve(Node* &head1 ,Node* &head2){
    //step1 reverse both ll
    head1 = reverse(head1);
    head2 = reverse(head2);
    //step2 add both ll
    Node* ansHead =NULL;
    Node* ansTail =NULL;
    int carry = 0;

    while(head1 != NULL && head2 != NULL){
        //calculate sum 
        int sum = carry+head1->data+head2->data;
        //digit to create node for
        int digit =sum%10;
        //caluclate carry 
        carry = sum/10;


        //crete a newnode for digit 
        Node* newNode =new Node(digit);
        //attach the newNodw into answer wali ll
        if (ansHead ==NULL){
            //first node
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail ->next =newNode;
            ansTail =newNode;
        }
        head1 =head1 ->next;
        head2 = head2->next; 

    }
    //jab head1 > head2 
    while(head1!=NULL){
        int sum =carry+head1->data ;
        int digit =sum%10;
        carry=sum/10;
        Node* newNode= new Node(digit);
        ansTail->next =newNode;
        ansTail =newNode;
        head1 = head1->next; 
    }
    //jab head1 < head2 
    while(head2!=NULL){
        int sum =carry+head2->data ;
        int digit =sum%10;
        carry=sum/10;
        Node* newNode= new Node(digit);
        ansTail->next =newNode;
        ansTail =newNode;
        head2 =head2 -> next;
    }
    //carry alone eg 99+99
    while(carry!=0){
        int sum =carry;
        int digit =sum%10;
        carry=sum/10;
        Node* newNode= new Node(digit);
        ansTail->next =newNode;
        ansTail =newNode;

    }

    //step3 reverse the ans ll
    ansHead =reverse(ansHead);
    return ansHead;
}

int main(){
    Node* head1 = new Node(2);
    Node* second1 = new Node(4);
    head1->next = second1;

    Node* head2 = new Node(2);
    Node* second2 = new Node(3);
    Node* third2= new Node(4);
    head2->next =second2;
    second2->next = third2;

    Node* ans =solve(head1 , head2);
    print(ans);
    

}