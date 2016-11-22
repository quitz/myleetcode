class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> r;
        if(s.length()<=10)
            return r;
        map<string,int> m;
        int i=0;
        while(i+10<=s.size()){
            string t = s.substr(i,10);
            m[t]++;
            i++;
        }
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>=2)
                r.push_back(it->first);
        }
        return r;
        /*for(int i=0;i<s.length()-10;i++){
            for(int j=i+1;j<s.length();j++){
                string a = s.substr(i,10);
                string b = s.substr(j,10);
                if(a.length() != b.length())
                    break;
                if(a == b)
                    r.push_back(a);
            }
            
        }
        //cout<<"line 19"<<endl;
        set<string> a(r.begin(),r.end());
        r.clear();
        for(auto it=a.begin();it!=a.end();it++)
            r.push_back(*it);
        return r;*/
    }
};