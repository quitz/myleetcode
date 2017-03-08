class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size() == 0)
            return 0;
        for(int i=0;;i++){
            for(int j=0;;j++){
                if(j == needle.size())
                    return i;
                if(i+j == haystack.size())
                    return -1;
                if(haystack[i+j] != needle[j])
                    break;
            }
        }
        return -1;
    }
};