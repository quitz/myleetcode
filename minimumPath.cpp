class Solution {
public:
    int minPathSum(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
            
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<int> r(col,0);
        vector<vector<int>> dp(row,r);
        /*if(obstacleGrid[row-1][col-1] == 1 || obstacleGrid[0][0]==1)
            return 0;*/
        dp[0][0] = obstacleGrid[0][0];
        for(int i=1;i<row;i++)
            dp[i][0] = dp[i-1][0]+obstacleGrid[i][0];
        
        for(int i=1;i<col;i++)
            dp[0][i] = dp[0][i-1]+obstacleGrid[0][i];
            
        for(int i=1;i<row;i++)
            for(int j=1;j<col;j++)
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+obstacleGrid[i][j];
            

        return dp[row-1][col-1];
    }
};