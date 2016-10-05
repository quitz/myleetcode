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
    ListNode* getmid(ListNode *head){
        ListNode *slow = head, *fast = head;
        while(slow && fast){
            fast = fast->next;
            if(fast==NULL)
                break;
            fast = fast->next;
            if(fast==NULL)
                break;
            slow = slow->next;
        }
        return slow;
    }
    void printList(ListNode *head){
        while(head!=NULL)
        {
            cout<<head->val<<" ";
            head= head->next;
            
        }
        cout<<endl;
        return;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *last = head, *mid = getmid(head);
        //cout<<"line30 "<<mid->val;
        while(last->next!=NULL){
            last=last->next;
        }
        ListNode *m = mid->next,*l1,*l2;
        mid->next = NULL;
        
        l1 = sortList(head);
        //printList(head);
        l2 = sortList(m);
        //printList(m);
        return merge(l1,l2);
        
    }
    
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode *res;
        if(first==NULL)
            return second;
        if(second ==NULL)
            return first;
        
        if(first->val<=second->val){
            res = first;
            first = first->next;
        }
        
        else{
            res = second;
            second = second->next;
        }
        
        ListNode *temp = res;
        while(first && second){
            if(first->val<=second->val){
                temp->next = first;
                temp = first;
                first = first->next;
            }
            else{
                temp->next = second;
                temp = second;
                second = second->next;
            }
        }
        if(first)
            temp->next = first;
        if(second)
            temp->next = second;
        return res;
        
            
    }
};