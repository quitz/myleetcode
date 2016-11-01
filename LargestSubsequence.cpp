int LargestSubsequence(vector<int> a)
{
    int len = a.size();
    if(size==0)
        return 0;
    int res =1,bestEnd = 0;
    vector<int> dp(len,1);
    vector<int> prev(len,-1);

    for(int i=0;i<len;i++){
        for(int j=0;j<i;j++){
            if(a[j]>a[i]){
                dp[i] = max(dp[i], dp[j]+1);
                prev[i] = j;
            }
        }

    }

    return dp[len-1];
}