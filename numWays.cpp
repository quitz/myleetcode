class Solution {
public:
//w(n)
    int numWays(int n, int k) {
        if(n==0 || k==0)
            return 0;
        int w1 = k, w2 = k*k, w3;
        if(n==1)
            return k;
        if(n==2)
            return k*k;
        for(int i=3;i<=n;i++){
            w3 = (k-1)*(w1+w2);
            w1 = w2;
            w2 = w3;
        }
        return w2;
    }
};