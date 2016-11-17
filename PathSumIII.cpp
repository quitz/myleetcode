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
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        int res = 0;
        findPath(sum, root, 0, res);
        
        res += pathSum(root->left, sum) + pathSum(root->right, sum);
        return res;
    }
    
    void findPath(int sum, TreeNode* root, int preSum, int& res){
        if(root == nullptr) return;
        preSum += root->val;
        res += preSum == sum ? 1 : 0;
        findPath(sum, root->left, preSum, res);
        findPath(sum, root->right, preSum, res);
        return;
    }
};