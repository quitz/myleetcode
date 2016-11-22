class Solution {
public:
    int longestPalindrome(string s) {
        int res;
        unordered_map<char, int> u;
        for(int i=0;i<s.length();i++)
            u[s[i]]++;
        int one=0,two=0;
        for(auto it=u.begin();it!=u.end();it++){
            if((it->second)%2==0)
                two += it->second;
            else{
                two += (it->second)-1;
                one=1;
            }
        }
        return two+one;
    }
};