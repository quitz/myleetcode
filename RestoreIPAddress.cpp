class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string t;
        dfs(0,0,s.length(),s,t,res);
        return res;
    }
    void dfs(int index, int start,int n,string &s, string& temp, vector<string>& res){
        if(index == 3){
            if(start>=n-3 && start<=n-1){
                int i = n-start;
                if(i>1 && s[start]=='0')
                    return;
                
                string t = s.substr(start);
                if(i==3 && atoi(t.c_str())>255)
                    return;
                
                
                temp += '.';
                temp += t;
                res.push_back(temp);
            }
            return;
        }
        for(int i=1;i<4;i++){
            if(start+i>n-1)
                break;
            if(i>1 && s[start]=='0')
                break;
            string t = s.substr(start,i);
            string u;
            u = temp;
            if(i==3 && atoi(t.c_str())>255)
                continue;
                
            if(temp!="")
                temp += '.';
            
            temp += t;
            dfs(index+1, start+i, n, s, temp, res);
            temp = u;
        }
            
    }
};