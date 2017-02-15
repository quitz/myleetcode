class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,vector<int>> mp,mp1;
        for(int i=0;i<s.length();i++)
            mp[s[i]].push_back(i);
        for(int i=0;i<t.length();i++)
            mp1[t[i]].push_back(i);
        
        set<vector<int>> a,b;
        for(auto item:mp){
            a.insert(item.second);
        }
        for(auto item:mp1){
            b.insert(item.second);
        }
         
        return a==b;  
        
    }
};