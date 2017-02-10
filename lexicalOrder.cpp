class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> r;
        if(n==0)
            return r;
        for(int i=1;i<10;i++)
            dfs(i,n,r);
        return r;
    }
    void dfs(int i, int n, vector<int>& r){
        if(i>n)
            return;
        
        r.push_back(i);
        for(int j=0;j<10;j++)
            dfs(i*10+j,n,r);
        return;
    }
};