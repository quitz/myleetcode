class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> q1(nums1.begin(),nums1.end());
        priority_queue<int> q2(nums2.begin(),nums2.end());
        vector<int> res;
        while(!q1.empty() && !q2.empty()){
            int t1 = q1.top();
            int t2 = q2.top();
            if(t1 == t2){
                q1.pop();
                q2.pop();
                res.push_back(t1);
            }
            else if(t1>t2){
                q1.pop();
            }
            else{
                q2.pop();
            }
        }
        return res;
        
    }
};