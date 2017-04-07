class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ret = 0;
        int i = 0, j = nums.size()-1;
        while(i<j){
            int mid = (i+j)/2;
            if(mid==0 || mid == nums.size()-1)
                return nums[mid];
                
            if(nums[mid] == nums[mid-1]){
                if((mid-1-i)%2 == 0)
                    i = mid+1;
                else
                    j = mid-2;
            }
            else if(nums[mid] == nums[mid+1]){
                if((j-mid-1)%2 == 0)
                    j = mid-1;
                else
                    i = mid+2;
            }
            else
                return nums[mid];
        }
        return nums[i];
    }
};