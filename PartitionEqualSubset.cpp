class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int len = nums.size(),t = 0;
        for(auto num:nums)
            t += num;
        if(t%2 !=0 )
            return false;
        int d = t/2;
        
        return judge(nums,0,len,d);
    }
    
    bool judge(vector<int> nums, int start, int len, int d){
        if(start == len)
            return false;
        if(start == len-1)
            return nums[start] == d;
        return judge(nums,start+1,len,d-nums[start]) || judge(nums,start+1,len,d);
    }
};