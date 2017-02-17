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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0)
            return nullptr;
        int a = postorder[postorder.size()-1];
        TreeNode *root = new TreeNode(a);
        auto idx = find(inorder.begin(),inorder.end(),a);
        auto idx1 = find(inorder.begin(),inorder.end(),a) - inorder.begin();
        vector<int> ia(inorder.begin(),idx),ib(idx+1, inorder.end());
        vector<int> pa(postorder.begin(),postorder.begin()+idx1),pb(postorder.begin()+idx1, postorder.end()-1);
        
        root->left = buildTree(ia,pa);
        root->right = buildTree(ib,pb);
        return root;
    }
};