class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        int r=3,dp[l+1];
        if(l == 0)
            return 0;
        if(l==1)
            return nums[0];
        dp[1] = nums[0];
        dp[2] = nums[0]>nums[1]?nums[0]:nums[1];
        while(r<=l){
            dp[r] = (dp[r-2]+nums[r-1])>dp[r-1]?dp[r-2]+nums[r-1]:dp[r-1];
            r++;
        }
        return dp[l];
    }
};