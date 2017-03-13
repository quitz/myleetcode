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

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int num : nums)
            ++m[num];
        
        vector<vector<int>> buckets(nums.size() + 1); 
        for (auto p : m)
            buckets[p.second].push_back(p.first);
        
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; --i) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};


class CompareDist
{
public:
    bool operator()(pair<int, int> n1, pair<int, int> n2) 
    {
        return n1.second > n2.second;
    }
};

class Solution 
{
public:
static bool comp(pair<int, int> n1, pair<int, int> n2){
    return n1.second>n2.second;
}
vector<int> topKFrequent(vector<int>& nums, int k) 
{
    vector<int> ret;
    unordered_map<int, int> htable;
    
    for (int key : nums) // get each key appears times
        htable[key]++;

    priority_queue<pair<int, int>, vector<pair<int, int> >, CompareDist> sheap; // use min heap to get k biggest
    for (auto elem : htable)
    {
        if (sheap.size() < k)
        {
            sheap.push(elem);
        }
        else
        {
            pair<int, int> heap_min = sheap.top();
            if (elem.second > heap_min.second)
            {
                sheap.pop();
                sheap.push(elem);
            }
        }
    }
    
    while (!sheap.empty())
    {
        pair<int, int> heap_min = sheap.top();
        ret.push_back(heap_min.first);
        sheap.pop();
    }
    reverse(ret.begin(), ret.end());
    
    return ret;
}
};