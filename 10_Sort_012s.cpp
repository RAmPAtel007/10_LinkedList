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
void sortWithReplacement(Node* head){
    //step 1 find count of 0 1 2's
    int zero=0 ; 
    int one=0;
    int two=0;

    Node* temp =head;
    
    while(temp!=NULL){
        if(temp->data==0){
            zero++;
        }
        else if(temp->data==1){
            one++;
        }
        else if(temp->data==2){
            two++;
        }
        temp =temp->next;
    }
    //step2 fill 
    temp=head;

        //fill zeros
        while(zero--){
            temp->data=0;
            temp=temp->next;
        } //fill 1
        while(one--){
            temp->data=1;
            temp=temp->next;
        }//fill 2
        while(two--){
            temp->data=2;
            temp=temp->next;
        }
    }
Node* sortWithoutReplacement(Node* head){
    //step 1 create dummy nodes (zeroNode/zeroHead)
    Node* zeroNode = new Node(-1);
    Node* zeroTail = zeroNode;

    Node* oneNode = new Node(-1);
    Node* oneTail = oneNode;

    Node* twoNode = new Node(-1);
    Node* twoTail = twoNode;
    //step 2 travese the original ll
    Node* curr =head;
    while(curr!=NULL){
        if(curr->data == 0){
            //take out the zero wali node 
            Node* temp =curr;
            curr =curr->next;
            temp->next =NULL;
            //append the zeroWaliNode LL
            zeroTail-> next =temp;
            zeroTail =temp;

        }
        else if(curr->data == 1){
             //take out the 1 wali node 
            Node* temp =curr;
            curr =curr->next;
            temp->next =NULL;
            //append the oneWaliNode LL
            oneTail-> next =temp;
            oneTail = temp;
            
        }
        else if(curr->data == 2){
             //take out the 2 wali node 
            Node* temp =curr;
            curr =curr->next;
            temp->next =NULL;
            //append the twoWaliNode LL
            twoTail-> next =temp;
            twoTail =temp;
            
        }
    }
    //yaha per 0 1 2 teeno LL ready hai 

    //modify one wali list 
    Node* temp = oneNode;
    oneNode =oneNode->next;
    temp->next=NULL;
    delete temp;

    //modify two wali list 
    temp = twoNode;
    twoNode =twoNode->next;
    temp->next=NULL;
    delete temp;

    //join them 
    if(oneNode !=NULL){
        //one wali list is non empty
        zeroTail ->next = oneNode;
        if(twoNode !=NULL){
            oneTail ->next =twoNode;
        }
    }
    else{
        //one wali list is empty
        if(twoNode !=NULL){
            zeroTail->next= twoNode;
        }
    }
    //remove zerohead dummy Node
    temp = zeroNode;
    zeroNode = zeroNode->next;
    temp ->next= NULL;
    delete temp;

    //return head of the modified ll
    return zeroNode;


}  

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(0);
    Node* fifth = new Node(0);
    Node* sixth = new Node(0);
    
    head->next =second;
    second->next =third;
    third->next =fourth;
    fourth->next =fifth;
    fifth->next =sixth;
    sixth->next =NULL;


    print(head);
    cout<<endl;
    // sortWithReplacement(head);
    // print(head);
    sortWithoutReplacement(head);
    print(head);
    cout <<endl;

}

