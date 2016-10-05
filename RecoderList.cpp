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
    void reorderList(ListNode* head) {
        ListNode *first, *last,*t1,*t2;
        first = head;
        last = head;
        stack<ListNode*> lastnode;
        int len=1,idx=1;
        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return;
        
        while(last->next!=NULL){
            last = last->next;
            len++;
        }
        t1 = first;
        for(int i=1;i<len;i++){
            if(i>len/2)
                lastnode.push(t1);
            
            t1 = t1->next;
        }
        
        t1 = first;
        
        while(1){
            t1 = first;
            t2 = first -> next;
            
            t1 = lastnode.top();
            //cout<<"t1: "<<t1->val;
            lastnode.pop();
            
            first -> next = t1->next;
            t1->next->next = t2;
            
            first = t2;
            last = t1;
            if(first == last){
                first->next = NULL;
                return;
            }
            else if(first->next == last){
                last->next = NULL;
                return;
            }
            
        }
        return; 
    }
};