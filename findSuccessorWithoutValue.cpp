struct TreeNode{
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
};

class solution{
    public:
        TreeNode *findsuc(TreeNode *root, TreeNode *p){
            if(p!=nullptr && p->right!=nullptr){
                TreeNode *t = p->right;
                while(t->left)
                    t = t->left;
                return t;
            }

            TreeNode *suc = p.parent;
            while(suc && suc.right == p){
                p = suc;
                suc = suc.parent;
            }
            return suc;
        }
}