class Solution {
public:
    void dfs(int index, int n, vector<bool>& left, vector<int>& temp, vector<vector<int>>& res){
    if(index == n)
    {
        res.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(!left[i])
            continue;
        left[i] = false;
        temp.push_back(i+1);
        dfs(index+1,n,left,temp,res);
        left[i] = true;
        temp.pop_back();
    }
}

string getPermutation(int n, int k) {
    vector<int> temp;
    vector<vector<int>> res;
    
    vector<bool> left(n,true);
    dfs(0,n,left,temp,res);
    
    temp = res[k-1];
    string t;
    for(int i=0;i<temp.size();i++)
        t += to_string(temp[i]);
    return t;
}
};