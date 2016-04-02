class Solution {
public:
    void dfs(int index, int n, vector<string>& temp,vector<bool>& left, map<int,int>& occ,vector<vector<string>>& res){
    if(index == n){
        res.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        //
        if(left[i]==false)
            continue;
        //bool isFind = false;
        int j=0;
        for(;j<index;j++){
            int t = occ[j];
            if(abs(index-j) == abs(i-t))
                break;
        }
        if(j != index)
            continue;
        
        string t(n,'.');
        t[i] = 'Q';
        temp.push_back(t);
        left[i] = false;
        occ[index] = i;
        dfs(index+1,n,temp,left,occ,res);
        left[i] = true;
        temp.pop_back();
        //occ[index][i]=0;
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    if(n<=3 && n!=1)
        return res;
    
    vector<string> temp;
    vector<bool> left(n,true);
    vector<int> r1(n,0);
    map<int,int> occ;
    dfs(0,n,temp,left,occ,res);
    return res;
}
};