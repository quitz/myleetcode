class Solution {
public:
    int numSquares(int n) {
        if(n<=1)
            return n;
        vector<int> r(n+1,INT_MAX);
        r[0] = 0;
        r[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=sqrt(i);j++)
                r[i] = min(r[i-j*j]+1,r[i]);
        }
        
        return r[n];
        
    }
};