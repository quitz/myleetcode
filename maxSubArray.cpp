class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    if(len ==0)
        return 0;
    int max1 = nums[0];
    int cur = nums[0];
    for(int i=1;i<len;i++){
        cur=cur<0?nums[i]:cur+nums[i];
        max1 = max(max1,cur);
    }
    return max1;
    }
};