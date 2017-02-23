class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)
            return 0;
        //vector<vector<int>> ret;
        //vector<int> temp;
        
        //dfs(nums, ret, temp, target);
        //return ret.size();
        vector<int> ret(target+1,0);
        ret[0] = 1;
        for(int i=1;i<ret.size();i++){
            for(int j=0;j<nums.size();j++)
            if(nums[j]<=i)
                ret[i] = ret[i] + ret[i-nums[j]];
        }
        
        return ret[target];
    }
    
    void dfs(vector<int>& nums, vector<vector<int>> &ret,vector<int> &temp, int target){
        if(target == 0){
            ret.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>target)
                continue;
            temp.push_back(nums[i]);
            dfs(nums,ret,temp,target-nums[i]);
            temp.pop_back();
        }
        return;
    }
};