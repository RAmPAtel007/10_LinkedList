/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a =headA;
        ListNode* b =headB;
        while(a->next && b->next){ //Continue the loop only if both a->next and b->next are NOT null.
         // It stops when either a->next or b->next becomes null.
        if(a==b){//same ll length 
            return a;
            }
        a=a->next;
        b=b->next;
        }
        if(a->next==NULL){
            //b is bigger 
            //now found how much bigger 
            int blen=0;
            while(b->next){
                blen++;
                b=b->next;
            }
            while(blen--){//setting the head at the same length..mtlb jo jitna bada hai uska head utna aage
            headB=headB->next;

            }
        }
        // if(b->next==NULL)
        else{
            //a is bigger 
            //now found how much bigger 
            int alen=0;
            while(a->next){
                alen++;
                a=a->next;
            }
            while(alen--){//setting the head at the same length..mtlb jo jitna bada hai uska head utna aage
            headA=headA->next;

            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
        
    }
};