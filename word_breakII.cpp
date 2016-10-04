class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        string kong;
        int len = s.length();
        
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
        
        vector<bool> possible(len+1, true);
        dfs(0,s,wordDict,kong,possible,dp,res);
        return res;
    }
    
    void dfs(int start, string s, unordered_set<string>& wordDict, string &temp, vector<bool> possible, vector<bool> dp, vector<string> &res){
        if(start>=s.length()){
            res.push_back(temp.substr(0,temp.size()-1));
            return;
        }
        for(int i=start;i<s.length();i++){
            string t = s.substr(start,i-start+1);
            if(wordDict.find(t)!=wordDict.end() && dp[i+1]){
                
                temp.append(t).append(" ");
                //int len1=res.size();
                dfs(i+1,s,wordDict,temp,possible,dp,res);
                /*int len2 = res.size();
                if(len1 == len2)
                    possible[i+1] = false;*/
                temp.resize(temp.size()-t.size()-1);
            }
        }
    }
};