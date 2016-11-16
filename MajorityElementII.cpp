class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        /*int len = nums.size();
        map<int,int> t;
        for(int i=0;i<len;i++)
            t[nums[i]]++;
        map<int,int>::iterator it = t.begin();
        for(;it!=t.end();it++){
            if(it->second>len/3)
                res.push_back(it->first);
        }*/
        int a,b,cnt1=0,cnt2=0;
        for(int num:nums){
            if(num == a)
                cnt1++;
            else if(num == b)
                cnt2++;
            else if(cnt1==0){
                cnt1++;
                a = num;
            }
            else if(cnt2==0){
                cnt2++;
                b = num;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        //cout<<a<<"  "<<b<<endl;
        cnt1=0,cnt2=0;
        for(int num:nums){
            if(num == a)
                cnt1++;
            if(num == b)
                cnt2++;
        }
        if (cnt1 > nums.size() / 3) res.push_back(a);
        if (cnt2 > nums.size() / 3) res.push_back(b);
        return res;
    }
};