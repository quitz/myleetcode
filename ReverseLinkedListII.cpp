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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *t1,*t2,*t3,*t4,*t5,*rb,*re,*cur,*pre,*nt;
        //t1 = head;
        if(m==n)
            return head;
        if(m>n)
            return NULL;
        if(m<=0)
            m = 1;
            
        ListNode u(0);
        u.next = head;
        int i=0;
        
        t1 = &u;
        while(i<n && t1!=NULL){
            t5 = t1;
            if(i==m-1)
                t2 = t1;//pre
            t1 = t1->next;
            i++;
        }
        if(t1 == NULL)
            t1 = t5;
        t3 = t1;      //later
        t4 = t3->next;
        
        //pr(head);
        rb = t2->next;
        re = t3;
        pre = rb;
        cur = rb->next;
        
        //t2->next = t3;
        rb ->next = t4;
        t2->next = t3;
        //pr(head);
        //pr(rb);
        
        while(cur!=t4){
            nt = cur->next;
            cur -> next = pre;
            //cout<<"line42"<<"nt val: "<<nt->val<<"cur val: "<<cur->val<<"pre val: "<<pre->val<<endl;
            //pr(cur);
            pre = cur;
            cur = nt;
            
            
        }
        //pr(t3);
        //pr(head);
        
        t2->next = t3;
        //pr(head);
        
        return u.next;
    }     
    void pr(ListNode *p){
        int i=0;
        while(p && i<10){
            cout<<p->val<<" ";
            p = p->next;
            i++;
        }
        cout<<endl;
    }
};