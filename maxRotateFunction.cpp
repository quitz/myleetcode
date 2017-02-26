class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len = A.size(),ret=INT_MIN;
        if(len == 0)
            return 0;
        /*int step = 0;
        
        for(int step=0;step<len;step++){
            int temp = 0;
            for(int j=0;j<len;j++){
                int base = (j+step) % len;
                temp += j * A[base];
            }
            ret = max(ret, temp);
        }*/
        int t=0,t1=0,t2=0;
        for(int i=0;i<len;i++){
            t += A[i];
            t1 += i*A[i];
        }
        ret = t1;
        
        for(int i=len-1;i>=1;i--){
            t1 = t1 + t - len*A[i];
            ret = max(ret, t1);
        }
        return ret;
    }
};