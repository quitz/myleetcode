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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        ListNode *dom = new ListNode(0);
        dom->next = head;
        ListNode *prev = dom, *cur = head, *nt = cur->next;
        while(nt){
            ListNode *t = nt->next;
            nt->next = prev->next;
            prev->next = nt;
            cur->next = t;
            
            nt = t;
        }
        return dom->next;
        
    }
};