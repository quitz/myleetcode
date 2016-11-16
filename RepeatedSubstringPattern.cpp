class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int len = str.length();
        if(len == 1)
            return false;
        
        for(int i=len/2;i>=1;i--){
            string t = str.substr(0,i);
            int m = i;
            int n = len%m;
            if( n!= 0 )
                continue;
            int j = 1, r=len/m;
            
            while(j<=r-1){
                string u = str.substr(j*i,i);
                //cout<<"line18"<<t<<"  "<<u<<endl;
                if(u != t)
                    break;
                j++;
            }
            
            if(j==r)
                return true;
            
        }
        return false;
    }
};