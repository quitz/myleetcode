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
    bool isPalindrome(ListNode* head) {
        if(head== NULL || head->next == NULL)
            return true;
        int len=0,i=0;
        ListNode *s = head, *f = head;
        while(f->next && f->next->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode *t = reverse(s->next);
        //pr(t);
        s->next = t;
        s = t;
        while(head && s){
            if(head->val != s->val)
                return false;
            head = head->next;
            s=s->next;
        }
        return true;
        
        
    }
    ListNode* reverse(ListNode *head){
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
    
    void pr(ListNode *head){
        while(head){
            cout<<head->val;
            head = head->next;
        }
        cout<<"line 56"<<endl;
    }
};