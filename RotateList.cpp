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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* nh =head,*t = head,*t1 = head,*res=NULL,*t2;
        if(head == NULL)
            return NULL;
        if(k==0)
            return head;
        int len = 0;
        while(nh!=NULL){
            len++;
            nh = nh->next;
        }
        int step = k%len;
        
        for(int i=1;i<=step;i++)
            t = t->next;
            
        if(t == head)
            return head;
        
        while(t->next!=NULL)
        {
            t = t->next;
            t1 = t1->next;
        }
        t2 = t1;
        t1 = t1-> next;
        t2->next=NULL;
        
        
        res = t1;
        
        while(t1->next!=NULL)
            t1 = t1->next;
        t1 ->next = head;
        
        return res;
    }
};