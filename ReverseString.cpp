class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        if(len<=1)
            return s;
        int i=0,j=len-1;
        while(i<j)
            swap(s[i++],s[j--]);
        return s;
    }
};