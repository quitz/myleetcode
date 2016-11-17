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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> u;
        vector<vector<int>> res;
        dfs(root,sum,u,res);
        return res;
    }
    
    void dfs(TreeNode* root, int sum, vector<int> u, vector<vector<int>> &res){
        if(root == NULL)
            return;
        TreeNode *l = root->left, *r = root->right;
        if(l==NULL && r==NULL && sum == root->val){
            
            u.push_back(root->val);
            res.push_back(u);
            //cout<<"line27 "<<res.size()<<endl;
            return;
        }
        int n = sum - root->val;
        
        if(l!=NULL){
            //cout<<"line29 "<<n<<"L:val "<<l->val<<endl;
            u.push_back(root->val);
            dfs(l,n,u,res);
            u.pop_back();
        }
        
        if(r!=NULL){
            //cout<<"line35 "<<n<<"R:val "<<r->val<<endl;
            u.push_back(root->val);
            dfs(r,n,u,res);
            u.pop_back();
        }
        return;
    }
};