class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        /*unordered_set<string>::iterator it;
        it = wordDict.find(s);
        if(it!=wordDict.end())
            return true;
        else{
            for(int i=s.length()-1;i>0;i--){
                string t = s.substr(0,i);
                string ex = s.substr(i, s.length());
                //cout<<"line12 t: "<<t<<" ex: "<<ex<<endl;
                if(wordBreak(t,wordDict)==true && wordBreak(ex, wordDict)==true)
                    return true;
            }
        }
        
        return false;*/
        
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        
        for(int i=1;i<=s.length();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] == true){
                    string t = s.substr(j,i-j);
                    if(wordDict.find(t) != wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
        
    }
};