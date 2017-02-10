class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        if(word == "")
            return vector<string> (1,"");
        vector<string> r = genString(word);
        vector<string> res;
        int len = word.length();
        for(auto item:r){
            int i=0;
            string ttt = item;
            while(i<item.length()){
                int l = 0;
                while(i<item.length() && item[i] == '1'){
                    l++;
                    i++;
                }
                if(l>=2){
                    string t = item.substr(0,i-l) + to_string(l) + item.substr(i);
                    item = t;
                    i-=l;
                    i++;
                }
                i++;
            }
            res.push_back(item);
        }
        return res;
    }
    
    vector<string> genString(string word){
        if(word.length() == 0)
            return vector<string>();
        vector<string> res;
        if(word.length() == 1){
            res.push_back(word);
            word[0] = '1';
            res.push_back(word);
            return res;
        }
        else{
            vector<string> t = genString(word.substr(1));
            for(int i=0;i<t.size();i++){
                res.push_back(word[0] + t[i]);
                res.push_back('1' + t[i]);
            }
            return res;
        }
            
    }
};