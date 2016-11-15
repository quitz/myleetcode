class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return nums[0];
        /*if(nums[0] < nums[len-1])
            return nums[0];
        for(int i=0;i<len-1;i++){
            if(nums[i] > nums[i+1])
                return nums[i+1];
        }
        return nums[0];*/
        if(nums[0] < nums[len-1])
            return nums[0];
        int low = 0, high = len-1;
        while(low!=high){
            mid = low+high/2;
            if(a[low]<a[mid]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
    }
};