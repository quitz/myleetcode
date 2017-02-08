class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size(),sum=0;
        for(auto i:nums)
            sum += i;
        int t = dfs(nums,0,len-1);
        return (2*t)>=sum;
        
    }
    
    int dfs(vector<int> &nums,int start, int end){
        if(start > end)
            return 0;
        if(start == end)
            return nums[start];
        return max(min(dfs(nums,start+1,end-1),dfs(nums,start+2,end)) + nums[start],min(dfs(nums,start+1,end-1),dfs(nums,start,end-2)) + nums[end]);
    }
};