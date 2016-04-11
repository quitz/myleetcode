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
            }
        }

        return sum;
    }
};
