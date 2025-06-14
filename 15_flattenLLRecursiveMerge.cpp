/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/
Node* merge(Node*a , Node*b){
    if(!a)return b ; ///agar a empty hua toh b  ko return kr do 
    if(!b) return a;
    Node* ans= 0;
    
    if(a->data < b->data){
        ans=a;
        a->bottom = merge(a->bottom,b);
        
    }
    else{
        ans=b;
        b->bottom = merge(a,b->bottom);
    }
    return ans;
}
class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(!root) return 0;
        Node* mergeLL = merge(root, flatten(root->next));
        return mergeLL;
        
    }
};

//note
// flatten(root->next) utomatically traverses till the last node in the main (horizontal) list using recursion.