/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *slow = head, *fast=head->next,*prev=nullptr;
        if(fast == nullptr)
            return new TreeNode(head->val);
            
        while(fast!= nullptr && fast->next!=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        fast = slow->next;
        if(prev==nullptr)
            head = nullptr;
        else
            prev->next = nullptr;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast);
        return root;
        
        
    }
};