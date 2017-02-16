class WordDistance {
public:
    map<string, vector<int>> mp;
    WordDistance(vector<string> words) {
        for(int i=0;i<words.size();i++)
            mp[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        vector<int> t1=mp[word1], t2=mp[word2];
        int d = INT_MAX;
        for(int i=0;i<t1.size();i++){
            for(int j=0;j<t2.size();j++){
                d = min(d,abs(t1[i]-t2[j]));
            }
        }
        return d;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */