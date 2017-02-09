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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *t = root;
        if(!root)
            return nullptr;
        
        if(root->val > key)
            root->left = deleteNode(root->left,key);
        if(root->val < key)
            root->right = deleteNode(root->right,key);
        if(root->val == key){
            if(!root->right)
                return root->left;
            else{
                t = root->right;
                while(t->left)
                    t = t->left;
                swap(root->val,t->val);
                root->right = deleteNode(root->right,key);
                return root;
                    
            }
        }
        return root;
    }
};