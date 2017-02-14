class Solution {
public:
    vector<string> generatePalindromes(string s) {
        map<char,int> mp;
        vector<string> r;
        vector<char> ch;
        char m;
        for(int i=0;i<s.length();i++)
            mp[s[i]]++;
        int a=0,b=0;
        for(auto item:mp){
            if(b>=2)
                return r;
            if(item.second % 2 != 0){
                int t = item.second/2;
                for(int j=0;j<t;j++)
                    ch.push_back(item.first);
                b++;
                m = item.first;
            }
            else{
                int t = item.second/2;
                for(int j=0;j<t;j++)
                    ch.push_back(item.first);
            }
        }
        if(b>=2)
            return r;
        string tmp(s.length(),' ');
        
        if(b==1)
            tmp[s.length()/2] = m;
        
        vector<bool> u(s.length(),false);
        
        dfs(0,ch,u,tmp,r);
        set<string> ret(r.begin(),r.end());
        vector<string> re(ret.begin(),ret.end());
        return re;
    }
    
    void dfs(int start, vector<char> ch,vector<bool> u,string t,vector<string>& r){
        if(start == t.length()/2){
            r.push_back(t);
            return;
        }
        
        for(int i=0;i<ch.size();i++){
            if(u[i])
                continue;
            u[i] = true;
            t[start] = ch[i];
            t[t.length()-1-start] = ch[i];
            dfs(start+1,ch,u,t,r);
            u[i]=false;
        }
        return;
    }
};