class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ret;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
            
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(pq.size() < k)
                pq.push(it->second);
            else{
                if(it->second > pq.top()){
                    pq.pop();
                    pq.push(it->second);
                }
            }
        }
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second >= pq.top())
                ret.push_back(it->first);
        }
        return ret;
        
    }
};