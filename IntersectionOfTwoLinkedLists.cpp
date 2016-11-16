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
        
        if(headA == NULL || headB==NULL)
            return NULL;
        ListNode *res;
        if(headA->val == headB->val)
            return headA;
        
        ListNode *t1 = headA, *t2 = headB;
        
        
        while(t1 && t2){
            if(t1->val == t2->val)
                return t1;
            else if(t1->val < t2->val)
                t1 = t1->next;
            else
                t2 = t2->next;
        }
        return NULL;
    }
};