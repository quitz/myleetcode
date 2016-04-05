class Solution {
public:
    string simplifyPath(string path) {
       int len = path.length();
       vector<string> by;
       string res;
       for(int i=0;i<len;i++){
           if(path[i]=='/'){
               int l = 0;
               int u = i;
               
               while(path[i+1]!='/' && path[i+1]!='\0'){
                   l++;
                   i++;
               }
               if(l==0)
                    continue;
               string temp = path.substr(u,l+1);
               
               if(temp=="/.."){
                   if(by.size()==0)
                        continue;
                   by.pop_back();
               }
               else if(temp=="/."){
                   continue;
               }
               else{
                   by.push_back(temp);
               }
           }
       }
       if(by.size()==0)
          return "/";
       else{
           for(int i=0;i<by.size();i++)
            res += by[i];
        
           return res;
       }
    }
};