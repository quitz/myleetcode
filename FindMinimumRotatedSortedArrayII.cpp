class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return nums[0];
        if(nums[0] < nums[len-1])
            return nums[0];
        int i=0;
        for(;i<len-1;i++){
            if(nums[i] > nums[i+1])
                return nums[i+1];
                
        }
        
        return nums[i];
    }
};