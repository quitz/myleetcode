
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
    }         //left[i] represents the number of occurence of target number from nums[0...i]
    
    
    //right[i] represents the number of occurence of not target number from nums[i...len-1]
    for(int i=nums.size()-1;i>=1;i--){
        
        if(nums[i] != target){
            if(i==nums.size()-1)
                right[i] = 1;
            else
                right[i] = right[i+1] + 1;
        }
        else
            right[i] = i==nums.size()-1?0:right[i+1];
        //in above, we have calculated the times of occurence of not target number from nums[i...len-1]
        //we have to compare right[i] with left[i-1]
        
        
        if(right[i] == left[i-1]){
            return i;
        }
    }
    return -1;
}