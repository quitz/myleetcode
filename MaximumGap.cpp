class Solution {
public:
    int maximumGap(vector<int>& nums) {
        /*int len=nums.size();
        if(len<2)
            return 0;
        priority_queue<int> r;
        for(int i=0;i<len;i++)
            r.push(nums[i]);
        
        int res = 0;
        int t1,t2;
        t1 = r.top();
        r.pop();
        t2 = r.top();
        r.pop();
        res = t1 - t2;
        int l1 = t2;
        int l2;
        for(int i=0;i<len;i++){
            l2 = r.top();
            r.pop();
            if(l1-l2 > res)
                res = l1-l2;
            l1 = l2;
        }
        return res;*/
        const int n = nums.size();
        if(n<=1) return 0;
        int maxE = *max_element(nums.begin(),nums.end());
        int minE = *min_element(nums.begin(),nums.end());
        double len = double(maxE-minE)/double(n-1);
        if(len==0)
            return 0;
        vector<int> maxA(n,INT_MIN);
        vector<int> minA(n,INT_MAX);
        for(int i=0; i<n; i++) {
            int index = (nums[i]-minE)/len;
            maxA[index] = max(maxA[index],nums[i]);
            minA[index] = min(minA[index],nums[i]);
        }
        int gap = 0, prev = maxA[0];
        for(int i=1; i<n; i++) {
            if(minA[i]==INT_MAX) continue;
            gap = max(gap,minA[i]-prev);
            prev = maxA[i];
        }
        return gap;
    }
};