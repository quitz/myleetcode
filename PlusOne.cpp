class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int len = digits.size();
        vector<int> res,res1;
        if(len==0)
            return res;
        int by = 1;
        int t = 0;
        for(int i=len-1;i>=0;i--){
            t = digits[i]+by;
            if(t>=10){
                by = 1;
                res.push_back(0);
            }
            else{
                res.push_back(t);
                by = 0;
            }
        }
        
        if(by==1)
            res.push_back(1);
        int llen = res.size();
        
        for(int i=0;i<llen;i++)
            res1.push_back(res[llen-1-i]);
        return res1;
        
    }
};
    /*vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        stack<int> use;
        long long t = 0;
        int len = digits.size();
        if(len==0)
            return res;
        for(int i=0;i<len;i++)
            t = t + digits[i] * pow(10,len-1-i);
        
        t = t+1;
        //cout<<t;
        while(t>0){
            use.push(t%10);
            t = t/10;
        }
      
        while(!use.empty()){
            res.push_back(use.top());
            use.pop();
        }
        
        return res;
    }* solution 1/ 
};