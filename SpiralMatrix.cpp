class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> u(n,0);
        vector<vector<int>> res(n,u);
        int len = (n+1)/2;
        int index=1;
        for(int i=0;i<len;i++){
            int lastrow = n-1-i;
            int lastcol = n-1-i;
            for(int k=i;k<=lastrow;k++)
                res[i][k] = index++;
            for(int k=i+1;k<=lastrow;k++)
                res[k][lastcol] = index++;
            for(int k=lastcol-1;k>=i;k--)
                res[lastrow][k] = index++;
            for(int k=lastrow-1;k>=i+1;k--)
                res[k][i] = index++;
        }
        return res;
    }
};