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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p)
            return nullptr;
        TreeNode *suc = nullptr;
        while(root){
            if(p->val < root->val){
                suc = root;
                root = root->left;
            }
            else
                root = root->right;
        }
        return suc;
    }
};