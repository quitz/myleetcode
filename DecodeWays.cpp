class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(len==0)
            return 0;
        vector<int> res(len+1,0);
        res[0] = 1;
        res[1] = s[0] == '0'?0:1;
        for(int i=2;i<=len;i++){
            if(s[i-1] == '0')
                res[i] = 0;
            else
                res[i] = res[i-1];
            
            if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1]<='6'))
                res[i] += res[i-2];
        }
        
        return res[len];
    }
    
};