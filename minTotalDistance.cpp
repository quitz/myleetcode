class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
       if(grid.empty() || grid[0].empty())
            return 0;
       int ret = 0;
       vector<int> row,col;
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++)
            if(grid[i][j] == 1){
                row.push_back(i);
                col.push_back(j);
            }
       }
       sort(row.begin(),row.end());
       sort(col.begin(),col.end());
       int i=0,j=row.size()-1;
       while(i<j){
           ret += row[j] - row[i];
           ret += col[j] - col[i];
           j--;i++;
       }
       return ret;
    }
};