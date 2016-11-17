class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        if(len==0)
            return 0;
        int t=0,m = 26;
        
        for(int i=0;i<len-1;i++){
            t += s[i] - 'A' + 1;
            t *= m;
        }
        t += s[len-1] - 'A' + 1;
        return t;
    }
};