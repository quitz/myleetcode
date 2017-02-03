class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return dfs(nums,0,S);
    }
    
    int dfs(vector<int>& nums, int start, int r){
        int len = nums.size();
        if(start>=len)
            return 0;
        if(start == len-1){
            if(nums[start] == r || -1*nums[start] == r)
                if(r==0)
                    return 2;
                else
                    return 1;
            else
                return 0;
        }
        
        return dfs(nums,start+1,r-nums[start]) + dfs(nums,start+1, r+nums[start]);
    }
};