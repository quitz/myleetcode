class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0)
            return 0;
        int ret = 1, t=1,s=1;
        while(t<=n){
            s++;
            if(t+s<=n){
                ret++;
                t+=s;
            }
            else
                return ret;
        }
        return ret;
        
    }
};