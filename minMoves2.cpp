class Solution {
public:
    int minMoves2(vector<int>& nums) {
        if(nums.size() <=1)
            return 0;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1,count=0;
        while(i<j){
            count += (nums[j--] - nums[i++]);
        }
        return count;
    }
};