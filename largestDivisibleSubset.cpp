class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> r;
        vector<vector<int>> res(nums.size());
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && res[j].size() > res[i].size())
                    res[i] = res[j];
            }
            res[i].push_back(nums[i]);
            if(r.size() < res[i].size() )
                r = res[i];
        }
        return r;
    }
};