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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return head;
        ListNode *t=head;
        ListNode *re,*pre;
        ListNode use(0);
        use.next = head;
        re = &use;
        int last = -99999;
        
        
        while(t!=NULL && t->next!=NULL){
            if(t->val == t->next->val){
                t->next = t->next->next;
                last = t->val;
                t = t->next;
                
            }
            else if(t->val == last)
                t = t->next;
            else{
                last = t->val;
                re ->next = t;
                re = re->next;
                t = t->next;
            }
            //cout<<t->val;
        }
        if(t==NULL || t->val==last)
            re->next = NULL;
        else 
            re->next = t;
            
        return use.next;
        
    }        
};