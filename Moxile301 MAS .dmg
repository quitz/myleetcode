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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        TreeNode *l = root->left, *r = root->right;
        if(l==NULL && r==NULL && sum == root->val)
            return true;
        
        bool res1,res2;
        if(l!=NULL){
            res1 = hasPathSum(l,sum - root->val);
        }
        if(r!=NULL)
            res2 = hasPathSum(r,sum - root->val);
            
        return res1 || res2;
    }
};