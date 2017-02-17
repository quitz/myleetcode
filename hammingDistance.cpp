class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x^y,r=0;
        while(t){
            if(t%2!=0)
                r++;
            t/=2;
        }
        return r;
    }
};