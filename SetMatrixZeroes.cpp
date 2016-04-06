class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res,res1;
        for(int i=0;i<row;i++){
            int j;
            vector<int> temp;
            for(j=0;j<col;j++){
                if(matrix[i][j]==0){
                    temp.push_back(j);
                    if(find(res1.begin(),res1.end(),j)==res1.end())
                        res1.push_back(j);
                }
            }
            if(temp.size()==0)
                continue;
            res.push_back(i);
        }
        for(int i=0;i<res.size();i++)
            for(int j=0;j<col;j++)
                matrix[res[i]][j] = 0;
        for(int i=0;i<res1.size();i++)
            for(int j=0;j<row;j++)
                matrix[j][res1[i]] = 0;
        return;
    }
};