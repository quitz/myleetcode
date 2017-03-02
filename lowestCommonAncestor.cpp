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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == nullptr || q == nullptr)
            return nullptr;
        queue<TreeNode*> que;
        que.push(root);
        map<TreeNode*, TreeNode*> mp;
        int flag = 0;
        
        while(!que.empty() && flag<2){
            int len = que.size();
            for(int i=0;i<len;i++){
                TreeNode *t = que.front();
                que.pop();
                if(t->left){
                    if(t->left == p || t->left == q)
                        flag++;
                    mp[t->left] = t;
                    que.push(t->left);
                }
                if(t->right){
                    if(t->right == p || t->right == q)
                        flag++;
                    mp[t->right] = t;
                    que.push(t->right);
                }
            }
        }
        
        vector<TreeNode*> p1,q1;
        p1.push_back(p);
        q1.push_back(q);
        
        while(mp.find(p)!=mp.end()){
            TreeNode *t = mp[p];
            p1.push_back(t);
            p = t;
        }
        
        while(mp.find(q)!=mp.end()){
            TreeNode *t = mp[q];
            q1.push_back(t);
            q = t;
        }
        
        for(int i=0;i<p1.size();i++)
            for(int j=0;j<q1.size();j++)
                if(p1[i] == q1[j])
                    return p1[i];
        
        return nullptr;
        
    }
};