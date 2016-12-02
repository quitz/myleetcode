class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> u(n+1,0);
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        u[0] = 10;
        u[1] = 9 * 9;
        int res = u[0] + u[1];
        for(int i=2; i<n; i++){
            u[i] = u[i-1]*(10-i);
            res += u[i];
        }
        return res;
    }
};