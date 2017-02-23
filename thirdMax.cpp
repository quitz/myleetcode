class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        set<int> a(nums.begin(),nums.end());
        vector<int> t(a.begin(),a.end());
        if(t.size()==1)
            return t[0];
        if(t.size()==2)
            return t[0]>t[1]?t[0]:t[1];
            
        int fir=max(t[0],max(t[1],t[2])),sec,thi=min(t[0],min(t[1],t[2]));
        sec = t[0] + t[1] + t[2] - fir - thi;
        
        for(int i=3;i<t.size();i++){
            if(t[i]<thi)
                continue;
            else if(t[i]>thi && t[i]<sec)
                thi = t[i];
            else if(t[i]<fir){
                thi = sec;
                sec = t[i];
            }
            else{
                thi = sec;
                sec = fir;
                fir = t[i];
            }
                
        }
        
        return thi;
        
    }
};