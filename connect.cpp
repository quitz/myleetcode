/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr)
            return;
        queue<TreeLinkNode*> q;
        vector<TreeLinkNode*> vec;
        q.push(root);
        while(!q.empty()){
            int len = q.size();
            int i=1;
            vec.clear();
            while(i<=len){
                TreeLinkNode *t = q.front();
                vec.push_back(t);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                q.pop();
                i++;
            }
            vec.push_back(nullptr);
            for(int j=0;j<vec.size()-1;j++)
                vec[j]->next = vec[j+1];
            
        }
        return;
    }
};