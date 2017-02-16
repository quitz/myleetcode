class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,h=0,z=0,k=1,ret=0;
        for(;h<nums.size();h++){
            if(nums[h]==0)
                z++;
            while(z>k){
                if(nums[l] == 0)
                    z--;
                l++;
            }
            ret = max(ret,h-l+1);
        }
        return ret;
    }
};