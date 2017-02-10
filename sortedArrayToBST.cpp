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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return nullptr;
        TreeNode *root = new TreeNode(nums[len/2]);
        if(len == 1)
            return root;
        vector<int> l(nums.begin(),nums.begin()+len/2);
        vector<int> r(nums.begin()+len/2+1,nums.end());
        
        root->left = sortedArrayToBST(l);
        root->right = sortedArrayToBST(r);
        return root;
    }
    void p(vector<int> v){
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
};