class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> r(1,1);
        vector<char> use(n,0);
        //r.push_back(0);
        string t;
        for(int i=2;i<=n;i++)
            r.push_back(r[i-2]*i);
            
        for(int i=0;i<n;i++)
            use[i] = (i+1) + '0';
            
        k = k-1;
        
        for(int i=n-2;i>=0;i--){
            int temp1 = r[i];
            int temp2 = k / temp1;
            t += use[temp2];
            
            k %= temp1;
            use.erase(use.begin()+temp2);
        }
        t += use[0];
        
        return t;
    }
};