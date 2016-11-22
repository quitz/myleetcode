class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases 
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //注意：这里的t2,t3,t5代表第x个丑数，丑数一定要由丑数*2，3，5中的一个来获得
        //，所以用3个变量表示第x个丑数，好进行比较。
        vector<int> k(n);
        k[0] = 1;
        for(int i  = 1; i < n ; i ++)
        {
            k[i] = min(k[t2]*2,min(k[t3]*3,k[t5]*5));
            if(k[i] == k[t2]*2) t2++; 
            if(k[i] == k[t3]*3) t3++;
            if(k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
    /*int nthUglyNumber(int n) {
        int r=0,i=0;
        while(r!=n){
            i++;
            if(isUgly(i))
                r++;
        }
        return i;
    }
    
    bool isUgly(int num){
        while(num%2==0)
            num /=2;
        while(num%3==0)
            num /=3;
        while(num%5==0)
            num /=5;
        return num==1;
    }*/
};