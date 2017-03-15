class Solution {
public:
void sortColors(vector<int>& nums) {
    int len = nums.size();
    if(len == 0 || len == 1)
        return;
    int idx0 = 0, idx1 = 0;
   
    for(int i=0;i<len;i++){
        if(nums[i]==0){
            nums[i] = 2;
            nums[idx1++] = 1;
            nums[idx0++] = 0;
        }
        else if(nums[i]==1){
            nums[i] = 2;
            nums[idx1++] = 1;
        }
    }    
    return;
  }

  void sortKColors(vector<int> &nums){
    int r = 0, w = 0, b = 0; // label the end of different colors
    for(int num:nums){
        if(num == 0){
            nums[b++] = 2;
            nums[w++] = 1;
            nums[r++] = 0;
        }
        else if(num == 1){
            nums[b++] = 2;
            nums[w++] = 1;
        }
        else(num == 2)
            b++;
    }
    
  }
};