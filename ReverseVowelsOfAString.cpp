class Solution {
public:
    string reverseVowels(string s) {
        int len = s.length();
        int i=0,j=len-1;
        set<char> al = {'a','e','i','o','u','A','E','I','O','U'};
        while(i!=j){
            while(!al.count(s[i]) && i<len)
                i++;
            if(i>=j)
                return s;
            while(!al.count(s[j]) && j>=0)
                j--;
            if(i==j)
                return s;
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};