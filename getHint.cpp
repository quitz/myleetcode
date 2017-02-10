class Solution {
public:
    string getHint(string secret, string guess) {
        int _a=0,_b=0;
        map<char,int> mp,mp1;
        for(int i=0;i<secret.size();i++){
            mp[secret[i]]++;
            mp1[guess[i]]++;
            if(secret[i] == guess[i])
                _a++;
        }
        auto it = mp.begin();
        for(;it!=mp.end();it++){
            char t = it->first;
            if(mp1.find(t) != mp1.end()){
                _b += min(it->second,mp1.find(t)->second);
            }
        }
        _b -= _a;
        string t=to_string(_a) + 'A' + to_string(_b) + 'B';
        return t;
    }
};