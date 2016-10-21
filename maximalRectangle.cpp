class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        /*int res = 0;
        int len = heights.size();
        if(len == 0)
            return res;
        int ll = (len*(len+1))/2;
        vector<int> use(ll,0);
        //vector<vector<int>> use(len,u);
        for(int i=0;i<len;i++){
            use[(2*len-i+1)*i/2 + (i-i)] = heights[i];
            res = max(res,heights[i]);
        }
            
        for(int i=1;i<len;i++)
            use[0][i] = min(use[0][i-1],heights[i]);
          
        for(int i=0;i<len;i++)
            for(int j=i+1;j<len;j++){
                use[(2*len-i+1)*i/2 + (j-i)] = min(use[(2*len-i+1)*i/2 + (j-1-i)],heights[j]); 
                res = max(use[(2*len-i+1)*i/2 + (j-i)]*(j-i+1), res);
            }
        for(int i=0;i<len;i++)
            for(int j=i;j<len;j++)
                
        
        return res;*/
        stack<int> s;
        //插入高度为0的bar
        height.push_back(0);

        int sum = 0;
        int i = 0;
        while(i < height.size()) {
            if(s.empty() || height[i] > height[s.top()]) {
                s.push(i);
                i++;
            } else {
                int t = s.top();
                s.pop();
                //这里还需要考虑stack为空的情况
                sum = max(sum, height[t] * (s.empty() ? i : i - s.top() - 1));
                //cout<<"i: "<<i<<"sum:  "<<sum<<endl;
            }
        }

        return sum;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row = matrix.size();
        if(row ==0)
            return 0;
        int col = matrix[0].size();
        if(col==0)
            return 0;
        
        vector<vector<int>> res(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == '0')
                    res[i][j] = 0;
                else{
                    res[i][j] = i==0?1:res[i-1][j]+1;
                }
            }
        }
        int maxarea = 0;
        for(int i=0;i<row;i++){
            maxarea = max(maxarea,largestRectangleArea(res[i]));
        }
        return maxarea;
        /*row++;
        col++;
        vector<vector<int>> res(row,vector<int>(col,0));
        res[1][1] = matrix[0][0];
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                res[i][j] = max(res[i-1][j],res[i][j-1]);
                if(matrix[i-1][j-1] != 0)
                    int a = area(matrix,i-1,j-1);
                
                res[i][j] = max(res[i][j],a);
                    /*int len1=1,len2=1,ti=i-1,tj=j-1;
                    ti--;
                    while(ti>=0 && matrix[ti][tj]!=0){
                        len1++;
                        ti--;
                    }
                    tj--;
                    if(tj>=0 && matrix[i-1][tj]!=0)
                        len1++;
                    
            }
        }
        return res[row-1][col-1];*/
    }
    
    
};