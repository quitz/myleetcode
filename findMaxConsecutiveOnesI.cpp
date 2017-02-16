class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int r = 0,i=0;
        while(i<nums.size()){
            int j=i;
            while(i<nums.size() && nums[i]==1)
                i++;
            r = max(r,i-j);
            i++;
        }
        return r;
    }
};