class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int index=0,i=0;
        vector<int> res;
        vector<string>::iterator it;
        int len = words[0].length();
        int len1 = words.size();
        if(len*len1>s.length() || len1==0)
            return res;
        map<string , int> w1,w2;
        
        for(int i=0;i<len1;i++)
            w1[words[i]]++;

        /*for(i=0;i<s.length();i++){
            int j=0;
            w2.clear();
            while(j<len1){
                string t(s,i+j*len,len);
                if(w1.find(t)==w1.end())
                    break;
                else{
                    w2[t]++;
                    if(w2[t]>w1[t]){
                        
                        break;
                    }
                    else
                        j++;
                }
            }
            if(j==len1)
                res.push_back(i);
        }*/
        for(i=0;i<len;i++){
            string t = s.substr(i,i+len);
            w2.clear();
            j=0;
            while(j<len1){
                
            }
        }
        return res;
}
        /*while(i<s.length()){
            string t(s,i,len);
            vector<string> backup(words);
            int aa = 0;
            while(backup.size()!=0){
                it = find(backup.begin(),backup.end(),t);
                if(it!=backup.end()){
                    i += len;
                    backup.erase(it);
                    t=string(s,i,len);
                    aa +=len;
                }
                else{
                    i = i - aa +1;
                    break;
                }
            }
            if(backup.size()==0){
                res.push_back(i-len*len1);
            }
        }*/
};