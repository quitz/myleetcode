struct TreeNode{
    int val;
    TreeNode* left;
    TreeNOde* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};
class solution{
  public:
    TreeNode* convert(string expr){
        if(expr.length() == 0)
            return nullptr;
        
        stack<TreeNode*> s;
        TreeNode *root = new TreeNode(expr[0]);
        s.push(root);

        for(int i=1;i<expr.length()-1;i+=2){
            TreeNode *t = new TreeNode(expr[i+1]);
            TreeNode *tmp;
            char c = expr[i];
            if(c == '?'){
                tmp = s.top();
                tmp ->left = t;
            }
            else{
                s.pop();

                tmp = s.top();
                while(tmp->right != nullptr)
                    s.pop();
                s.pop()->right = t;

            }

            s.push(t);
        }
        return root;
    }
}