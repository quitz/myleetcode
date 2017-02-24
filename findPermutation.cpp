class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size()+1;
        if(n == 1)
            return vector<int>(1,1);
        
        int t,i=s.size()-1;
        while(i>=0 && s[i] == 'D')
            i--;
        t = i+1;
        vector<int> te = findPermutation(s.substr(0,s.size()-1));
        
        te.insert(te.begin()+t,n);
        return te;
    }
};