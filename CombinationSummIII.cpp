class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(n<=0 || n>45)
            return res;
        vector<int> temp;
        vector<bool> used(10,false);
        int start = 1;
        dfs(k,n,start,temp,used,res);
        return res;
    }
    
    void dfs(int k, int n, int start,vector<int> temp, vector<bool> used, vector<vector<int>> &res){
        if(k==0 && n==0){
            res.push_back(temp);
            //cout<<"line16 "<<res.size();
            return;
        }
        if(k==0 || n==0)
            return;
        for(int i=start;i<=9;i++){
            if(used[i])
                continue;
            used[i] = true;
            temp.push_back(i);
            dfs(k-1,n-i,i+1,temp,used,res);
            temp.pop_back();
            used[i] = false;
        }
        return;
        
    }
};