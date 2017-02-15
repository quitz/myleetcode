/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        queue<TreeNode *> q;
        if(root == nullptr)
            return ret;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            int i=1;
            while(i<=s){
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp == nullptr)
                    ret = ret + ",null";
                else{
                    ret = ret + ',' + to_string(tmp->val);
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
                i++;
            }
        }
        return ret.substr(1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;
        vector<string> s;
        int i=0,j;
        while(i<data.length()){
            if(data[i]==',')
                i++;
            j=i;
            while(i<data.length() && data[i]!=',')
                i++;
            string tmp = data.substr(j,i-j);
            s.push_back(tmp);
        }
        
        TreeNode *root = new TreeNode(stoi(s[0]));
        vector<TreeNode*> tr;
        tr.push_back(root);
        int cur = 0,lr = 0;
        for(int i=1;i<s.size();i++,lr++){
            if(s[i] == "null"){
                if(lr%2 == 0)
                    tr[cur]->left = nullptr;
                else
                    tr[cur++]->right = nullptr;
            }
            else{
                TreeNode *tmp = new TreeNode(stoi(s[i]));
                if(lr%2 == 0){
                    tr[cur]->left = tmp;
                }
                else{
                    tr[cur++]->right = tmp;
                }
                
                tr.push_back(tmp);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));