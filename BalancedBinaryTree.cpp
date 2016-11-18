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
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int l = maxHeight(root->left), r = maxHeight(root->right);
        if(abs(l-r)>=2)
            return false;
        return isBalanced(root->left)&&isBalanced(root->right);
        
    }
    
    int maxHeight(TreeNode *root){
        if(root==NULL)
            return 0;
        return 1+max(maxHeight(root->left),maxHeight(root->right));
    }
};