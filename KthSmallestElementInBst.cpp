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
    struct TreeNodeCount{
        int val;
        int count;
        TreeNodeCount *left;
        TreeNodeCount *right;
        TreeNodeCount(int x) : val(x), count(1),left(NULL),right(NULL) {}
    };
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        TreeNodeCount *tnc = buildtnc(root);
        return findele(tnc,k);
    }
    TreeNodeCount* buildtnc(TreeNode *root){
        if(root == NULL)
            return NULL;
        TreeNodeCount *ntnc = new TreeNodeCount(root->val);
        ntnc->left = buildtnc(root->left);
        ntnc->right = buildtnc(root->right);
        if(ntnc->left)
            ntnc->count += ntnc->left->count;
        if(ntnc->right)
            ntnc->count += ntnc->right->count;
        
        return ntnc;
    }
    
    int findele(TreeNodeCount *root, int k){
        if(root == NULL || k>root->count || k<=0)
            return -1;
        
        if(root->left!=NULL){
            int t = root->left->count;
            if(k==t+1)
                return root->val;
            if(k<t+1)
                return findele(root->left,k);
            else
                return findele(root->right,k-t-1);
        }
        else{
            if(k==1)
                return root->val;
            return findele(root->right,k-1);   
        }
    }
    
    /*int countNode(TreeNode *root){
        int res=0;
        if(root==NULL)
            return 0;
        res++;
        return res + countNode(root->left) + countNode(root->right);
        
    }*/
};