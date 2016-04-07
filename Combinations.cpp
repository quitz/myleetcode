class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(n==0 || n<k)
            return res;
        vector<int> temp;
        vector<bool> use(n,false);
        dfs(0,0,n,k,temp,use,res);

        return res;
    }
    void dfs(int index, int start, int n, int k, vector<int> &temp, vector<bool> &use, vector<vector<int>> &res){
        if(index == k){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<n;i++){
            if(use[i]==true)
                continue;
            use[i] = true;
            temp.push_back(i+1);
            dfs(index+1,i,n,k,temp,use,res);
            use[i] = false;
            temp.pop_back();
        }
    }
};