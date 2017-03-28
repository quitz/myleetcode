class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        multiset<int> window;
        
        for(int i=0;i<nums.size();i++){
            window.insert(nums[i]);
            
            if(window.size()>k)
                window.erase(window.find(nums[i-k]));
                
            if(window.size() == k){
                auto it = window.begin();
                advance(it,k/2);
                if(k%2 == 1)
                    ret.push_back(*it);
                else
                    ret.push_back(*it / 2.0 + *(--it)/2.0);
            }
        }
        return ret;
    }
};