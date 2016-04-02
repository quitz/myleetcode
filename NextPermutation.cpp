class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    int len = nums.size();
    if(len==1)
        return;
    int i= len-1;
    int ei,ej;
    int right,left;
    
    right = i;
    if(nums[i]>nums[i-1]){
        ei = i;
        ej = i-1;
        swap(nums[i],nums[i-1]);
        return;
    }
    
    while(i!=0 && nums[i]<=nums[i-1]){
        i--;
    }
    if(i==0)
        return sort(nums.begin(),nums.end());
    
    else{
        int index = i-1;
        bool flag = true;
        int j=i+1;
        for(;j<len;j++){
            if(nums[j]>nums[index])
                continue;
            else{
                break;
                flag = false;
            }
        }
        swap(nums[j-1],nums[index]);
        /*vector<int> res;
         for(int kk=0;kk<=index;kk++){
         res.push_back(nums[kk]);
         }*/
        sort(nums.begin()+index+1,nums.end());
        return;
    }
 }
};