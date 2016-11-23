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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* t;
    Solution(ListNode* head) {
        t = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* u = t;
        int res = t->val;
        u=u->next;
        int len=1;
        while(u!=NULL){
            len++;
            int idx = rand()%len;
            if(idx == 0)
                res = u->val;
            u = u->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */