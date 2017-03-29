class Solution {
public:
//dp[i][j] represents the minimum cost of house 0...i and house[i] using color costs[i][j], return min(house[len][i])
//dp[i][j] = costs[i][j] + min(dp[i-1][k],k!=j)
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty())
            return 0;
        vector<vector<int>> dp(costs.size(), vector<int>(costs[0].size(),INT_MAX));
        for(int i=0;i<costs[0].size();i++)
            dp[0][i] = costs[0][i];
        
        for(int i=1;i<costs.size();i++){
            for(int j=0;j<costs[i].size();j++){
                for(int k=0;k<costs[i].size();k++){
                    if(k == j)
                        continue;
                    dp[i][j] = min(dp[i][j], costs[i][j] + dp[i-1][k]);
                    //cout<<"line 18 "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                } 
            }
        }
        
        int ret= INT_MAX;
        for(int i=0;i<costs[0].size();i++)
            ret = min(dp[costs.size()-1][i], ret);
            
        return ret;
        
    }
};