class Solution {
public:
    int integerBreak(int n) {
        int *dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                int t1 = max(dp[j]*dp[i-j],dp[j]*(i-j));
                int t2 = max(j*dp[i-j],j*(i-j));
                int t3 = max(t1,t2);
                dp[i] = max(dp[i],t3);
                //cout<<"line 13 i: "<<i<<"dp[i]: "<<dp[i]<<endl;
            }
        }
        
        return dp[n];
    }
};