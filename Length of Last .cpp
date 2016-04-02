class Solution {
public:
    int lengthOfLastWord(string s) {
        int i,j;
        int len = s.length();
        if(len==0)
            return 0;
        
        for(i=len-1;i>=0;i--)
            if(s[i]!=' ')
                break;
        
        if(s[i] == ' ')
            return 0;
            
        for(j=i;j>=0;j--)
            if(s[j]==' ')
                break;
        
        return i-j;
        /*int res=0,cur=0;
        int len = s.length();
        if(len==0)
            return 0;
        if(len==1)
            return s[0]==' '?0:1;
        vector<int> use;
        int start=0,end=0;
        for(int i=0;i<len;i++){
            if(s[i]!=' ')
                end++;
            else{
                //use.push_back(cur);
                //cur = 0;
                //start = i+1;
                if(start!=end)
                    cur = end - start;
                start = i+1;
                end = start;
            }
            //res = max(res,cur);
        }
        if(end - start!=0)
            return end - start;
        return cur;*/
    }
};