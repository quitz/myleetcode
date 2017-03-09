class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,0,nums.size()-1,nums.size()-k);
    }
    
    int quickSelect(vector<int>& nums, int low, int high, int k){
        int tar = nums[low], i = low, j = high;
        while(i < j){
            while(i<j && nums[j] >= tar)
                j--;
            if(i<j)
                nums[i++] = nums[j];
            while(i<j && nums[i] <= tar)
                i++;
            if(i<j)
                nums[j--] = nums[i];
        }
        nums[i] = tar;
        if(i == k)
            return tar;
        else if(i > k)
            return quickSelect(nums,low,i-1,k);
        else
            return quickSelect(nums,i+1,high,k);
    }
};