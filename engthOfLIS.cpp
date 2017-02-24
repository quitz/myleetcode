class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        int  ret = 1;
        vector<int> r(nums.size(),1);
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    r[i] = max(r[i],r[j]+1);
            }
            ret = max(ret,r[i]);
        }
        return ret;

    }
};