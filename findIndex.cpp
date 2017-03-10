class solution{
  public:
    int findIndex(vector<int> nums, int target){
        vector<int> left(nums.size(),0), right(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target){
                if(i == 0)
                    left[i] = 1;
                else
                    left[i] = left[i-1] + 1;
            }
            else
                left[i] = i==0?0:left[i-1];
        }

        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] != target){
                if(i==nums.size()-1)
                    right[i] = 1;
                else
                    right[i] = right[i+1] + 1;

                if(left[nums.size()-1-i] == right[i])
                    return nums.size()-1-i;
            }
            else
                right[i] = i==nums.size()-1?0:right[i+1];
        }
        return -1;
    }  
};