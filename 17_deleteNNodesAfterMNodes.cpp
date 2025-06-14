/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        if(!head) return NULL ;
        Node* it =head;
        for(int i=0 ; i<m-1 && it!=NULL; i++){
            //if M nodes are not present 
            if(!it) return NULL;
            it=it->next;
        }
        if(!it) return NULL;
        //it would be at Mth Node 
        Node* MthNode = it;
        it= MthNode->next;
        for(int i =0 ;i< n;i++){
            if(!it) break;
            Node* temp = it->next;
            delete it;
            it=temp;
        }
        
        MthNode->next =it;
        linkdelete(it,n,m);
        return head;
    
    }
};