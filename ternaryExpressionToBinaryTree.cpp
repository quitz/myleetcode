 /*
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
    TreeNode* convert(string expr) {
        if (expr.size() == 0) {
            return 0;
        }
        TreeNode *root = new TreeNode(expr[0]);
        Stack<TreeNode*> s;
        s.push(root);
        
        for(int i=1;i<expr.size();i+=2){
            TreeNode *t = new TreeNode(expr[i+1]);
            
            if(expr[i] == '?'){
                TreeNode *tp = s.top();
                tp->left = t;
            }
            else if(expr[i] == ':'){
                s.pop();
                TreeNode *tp = s.top();
                while(s.top()->right != nullptr)
                    s.pop();
                s.top()->right = t;
            }
            s.push(t);
        }

        return root;
    }
};