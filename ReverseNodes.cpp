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
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dum(0);
    dum.next = head;
    ListNode *pre = &dum;
    ListNode *t1,*t2,*t3,*f,*temp;
    vector<ListNode*> res;
    
    while(head!=NULL){
        int i=1;
        t1 = head;
        t2 = pre;
        while(i<=k && t1!=NULL){
            res.push_back(t1);
            //t2 =t1;
            t1 = t1->next;
            i++;
        }
        if(i<=k)
            break;
        //f = res[k-1];
        f = t1;
        temp = pre;
        for(int j=k-1;j>=0;j--){
            //t2 = res[j];
            //t3 = res[j-1];
            temp->next=res[j];
            temp = temp->next;
        }
        res[0]->next =f;
        pre = res[0];
        res.clear();
        head = t1;
        
    }
    return dum.next;
    
}
};