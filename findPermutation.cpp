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
    vector<int> findPermutation(string s) {
        vector<int> ret;
    for (int i = 0; i <= s.size(); ++i) {
      if (i == s.size() || s[i] == 'I') {
        int retLen = ret.size();
        for (int countD = i - retLen + 1; countD > 0; --countD) ret.push_back(retLen + countD);
      }
    }
    return ret;
}   
};