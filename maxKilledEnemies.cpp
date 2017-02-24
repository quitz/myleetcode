class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int row = grid.size(),col=grid[0].size();
        vector<vector<int>> dp1(row,vector<int>(col,0)), dp2(row,vector<int>(col,0));
        
        int ret=0;
        for(int i=0;i<row;i++){
            int j=0,cnt=0;
            while(j<col){
                int t = j;
                cnt = 0;
                while(j<grid[i].size() && grid[i][j]!='W'){
                    if(grid[i][j]=='E')
                        cnt++;
                    j++;
                }
                
                for(int k=t;k<j;k++)
                    dp1[i][k] = cnt;
                //cout<<"line23:"<<endl;
                if(j!=grid[i].size())
                    dp1[i][j] = 0;
                //cout<<"line25:"<<endl;
                j++;
                
            }
        }
            
        for(int i=0;i<col;i++){
            int j=0,cnt;
            while(j<row){
                int t = j;
                cnt = 0;
                while(j<row && grid[j][i]!='W'){
                    if(grid[j][i]=='E')
                        cnt++;
                    j++;
                }
                for(int k=t;k<j;k++)
                    dp2[k][i] = cnt;
                
                if(j!=row)
                    dp2[j][i] = 0;
                
                j++;
            }
        }
        

        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int t = dp1[i][j]+dp2[i][j];
                if(grid[i][j] == '0')
                    ret = max(ret,t);
            }
        }
        return ret;
        
        
        
    }
};