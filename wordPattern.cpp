class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> a;
        map<string,char> b;
        int j=0,t,k;
        for(int i=0;i<pattern.length();i++){
            t = j;
            if(str[t] == ' '){
                t++;
                j++;
            }
            while(j<str.length() && str[j]!=' ')
                j++;
            if(j==t)
                return false;
            string t1 = str.substr(t,j-t);
            
            if(!a.count(pattern[i]))
                a[pattern[i]] = t1;
            if(a[pattern[i]] != t1)
                return false;
            if(!b.count(t1))
                b[t1] = pattern[i];
            if(b[t1] != pattern[i])
                return false;
            a[pattern[i]] = t1;
            b[t1] = pattern[i];
            
        }
        
        return j==str.length();
    }
};