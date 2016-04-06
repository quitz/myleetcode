class Solution {
public:
    /*bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++){
            if(target>=matrix[i][0] && target<=matrix[i][col-1]){
                for(int j=0;j<col;j++){
                    if(target == matrix[i][j])
                        return true;
                }
            }
            else
                continue;
        }
        return false;
    }*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0, high = row-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][col-1]){
                for(int j=0;j<col;j++){
                    if(target == matrix[mid][j])
                        return true;
                }
                return false;
            }
            else if(target<matrix[mid][0])
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
        /*for(int i=0;i<row;i++){
            if(target>=matrix[i][0] && target<=matrix[i][col-1]){
                for(int j=0;j<col;j++){
                    if(target == matrix[i][j])
                        return true;
                }
            }
            else
                continue;
        }
        return false;*/
    }
};