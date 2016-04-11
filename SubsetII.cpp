class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n==0)
            return res;
        vector<int> temp;
        vector<bool> use(n,false);
        res.push_back(temp);
        sort(nums.begin(),nums.end());
        dfs(0,0,n,temp,use,res,nums);
    
        return res;
    }
    
    void dfs(int index, int start, int n, vector<int> &temp, vector<bool> &use, vector<vector<int>> &res, vector<int> &nums){
        if(index == n){
            return;
        }
        for(int i=start;i<n;i++){
            
            if(use[i]==true || (i>0 && nums[i] == nums[i-1] && use[i-1] == false))
                continue;

            use[i] = true;
            temp.push_back(nums[i]);
            res.push_back(temp);
            dfs(index+1,i+1,n,temp,use,res,nums);
            use[i] = false;
            temp.pop_back();
        }
    }
    
};