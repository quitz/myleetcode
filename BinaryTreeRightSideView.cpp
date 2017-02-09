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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> r;
        if(!root)
            return r;
        vector<vector<int>> d;
        TreeNode *t = root;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int> u;
            for(int i=0;i<n;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                u.push_back(temp->val);
            }
            d.push_back(u);
        }
        
        for(int i=0;i<d.size();i++){
            r.push_back(d[i].back());
        }
        return r;    
    }
    
};