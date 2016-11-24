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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dum = new ListNode(0);
        dum->next = head;
        ListNode *prev,*cur,*nt;
        prev = dum;
        cur = head;
        //nt = cur->next;
        while(cur){
            while(cur && cur->val == val)
                cur = cur->next;
            
            prev->next = cur;

            prev = cur;
            if(cur)
                cur = cur->next;
        }
        return dum->next;
    }
};