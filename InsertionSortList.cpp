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
    void printList(ListNode *head, ListNode *end){
        while(head!=NULL)
        {
            cout<<head->val<<" ";
            if(head == end)
                break;
            head= head->next;
            
        }
        cout<<endl;
        return;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode *start = head, *end=head, *t=head;
        if(head == NULL || head->next ==NULL)
            return head;
        t  = head->next;
        
        while(t!=NULL){
            ListNode *temp_next = t->next;
            if(t->val<=start->val){
                t->next = start;
                start = t;
            }
            else if(t->val>=end->val){
                end->next = t;
                end = t;
            }
            else{
                ListNode *temp = start->next,*temp1 = start;
                
                while(t->val>=temp->val){
                    temp1 = temp;
                    temp = temp->next;
                }
                
                temp1->next = t;
                t->next = temp;
            }
            //printList(start,end);
            t = temp_next;
            
        }
        end->next = NULL;
        return start;
    }
};