class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret, curMax, curMin;
        int n = nums.size();
        ret = curMax = curMin = nums[0];
        for(int i=1; i<n; i++) {
            int temp = curMax;
            curMax = max(max(curMax*nums[i], curMin*nums[i]),nums[i]);
            curMin = min(min(temp*nums[i], curMin*nums[i]),nums[i]);
            ret = max(ret, curMax);
        }
        return ret;
    }
};