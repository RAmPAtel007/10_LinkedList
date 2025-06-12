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
bool checkPalindrome(Node* head){
    if(head == NULL){
        cout<<"LL is empty"<<endl;
        return true;
    }
    if(head->next ==NULL){
        return true;
    }
    //step 1 middle find
    Node* slow = head;
    Node* fast = head->next; 
    while(fast!=NULL){
        fast = fast -> next;
        
        if(fast!=NULL){
            fast = fast -> next;
            slow = slow -> next;

        }      
    }
    // return slow; // yaha tak agar aa gaya hai code toh slow is pointing middle/slow element 

    //step 2 reverse LL
    Node* reverseLLKaHead = reverse(slow->next);

    slow->next =reverseLLKaHead;//mtlb ki reverse wali lo connect kt diya slow pointer se 

    //step 3 compare
    Node* temp1 = head;
    Node* temp2 = reverseLLKaHead;

    while(temp2!=NULL){
        if(temp1->data != temp2->data){
            //not palindeome q ki qual he nahi hai 
            return false;
        }
        else{
            temp1= temp1->next;
            temp2= temp2->next;
            
        }
    }
    return true;
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(20);
    Node* fifth= new Node(10);
    
    head->next =second;
    second->next =third;
    third->next =fourth;
    fourth->next =fifth;
    fifth->next =NULL;

    print(head);
    cout<<endl;
    bool isPalindrome = checkPalindrome(head);

    if(isPalindrome){
        cout<<"LL is palindrome"<<endl;
    }
    else{
        cout<<"LL is not palindeome"<<endl;
    }

}