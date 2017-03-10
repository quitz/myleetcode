/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *parent;
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

    int combine(vector<int> &nums){
        int ret = 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(auto num:nums)
            pq.push(num);

        while(!pq.empty()){
            int t1 = pq.top(), t2 = 0;
            pq.pop();
            if(!pq.empty())
                t2 = pq.top();
            ret = t1+t2;
            if(pq.empty())
                return ret;
            pq.push(ret);
        }
        return ret;
    }

};