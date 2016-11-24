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
        vector<ListNode*> r;
        ListNode *t = head;
        
        while(t!=NULL){
            r.push_back(t);
            t = t->next;
        }
        
        for(int i=0;i<r.size()/2;i++){
            if(r[i]->val != r[r.size()-i-1]->val)
                return false;
        }
        return true;
        
        
    }
};