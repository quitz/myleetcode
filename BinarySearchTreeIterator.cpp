/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> res;
    int len;
    void Traverse(TreeNode *root){
        if(root == NULL)
            return;
        if(root->left==NULL)
            res.push_back(root->val);
        else{
            Traverse(root->left);
            res.push_back(root->val);
        }
        if(root->right!=NULL)
            Traverse(root->right);
    }
    BSTIterator(TreeNode *root) {
        len = -1;
        Traverse(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        len++;
        if(len<res.size())
            return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        return res[len];
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */