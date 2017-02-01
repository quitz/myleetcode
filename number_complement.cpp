class Solution {
public:
    int findComplement(int num) {
        if(num == 0)
            return 1;
        stack<int> r;
        
        while(num>0){
            r.push(num%2);
            num/=2;
        }
        int t,res=0;
        while(!r.empty()){
            t = r.top();
            r.pop();
            res = res*2 + (t+1)%2;
        }
        
        return res;
        
    }
};