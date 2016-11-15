class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length(), len2 = version2.length();
        int i=0,j=0,m,n;
        string t1,t2;
        while(i<len1 || j<len2){
            while(i<len1 && version1[i]!='.'){
                t1.push_back(version1[i++]);
            }
            if(t1 == "")
                m = 0;
            else
                m = stoi(t1);
            while(j<len2 && version2[j]!='.'){
                t2.push_back(version2[j++]);
            }
            if(t2 == "")
                n = 0;
            else
                n = stoi(t2);
            //cout<<m<<"  "<<n;
            if(m>n)
                return 1;
            else if(m<n)
                return -1;
            
            t1.clear();
            t2.clear();
            i++;
            j++;
        }
        return 0;
    }
};