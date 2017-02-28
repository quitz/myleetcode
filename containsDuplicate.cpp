class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(auto item:nums){
            if(mp.find(item)!=mp.end())
                return true;
            mp[item] = 1;
        }
        return false;
    }
};