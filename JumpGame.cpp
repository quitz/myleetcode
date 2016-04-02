class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool res;
        int n = nums.size();
        if(n==0)
            return false;
       
        int start=0,end=0,max=0;
        int i=0;
        while(end<n-1){
            for(int j=start;j<=end;j++){
                int temp = nums[i];
                max = j+nums[j]>max?j+nums[j]:max;
            }
            if(max == end)
                return false;
            start = end+1;
            end = max;
            
        }
        if(end == n-1)
            return true;
        
    }
};