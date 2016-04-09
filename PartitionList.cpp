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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        
        ListNode *t,*t1, *pre,*cur,*temp;
        ListNode u(0);
        u.next = head;
        pre = &u;
        cur = &u;
        int i=0;
        while(cur->next!=NULL){
            
            if(cur->next->val>=x)
                cur = cur->next;
            else{
                
                if(cur == pre){
                    cur = cur->next;
                    pre->next = cur;
                }
                else{
                    
                    temp = cur->next;
                    
                    cur -> next = temp -> next;
                    
                    temp -> next = pre -> next;
                    
                    pre -> next = temp;
                    
                    
                }
                pre = pre->next;
                
            }
            
            
        }
        
        return u.next;
        
    }

};