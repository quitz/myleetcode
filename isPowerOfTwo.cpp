/*power of 2 always get 1 at the leftmost bit and 0s at other bits.
So n-1 get every bit 1 if n is power of 2, n&(n-1) equals to 0 (false).s
In other cases it is not going to be all zeros.*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n & (n-1));
    }
};