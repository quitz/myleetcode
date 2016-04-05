class Solution {
public:
    string addBinary(string a, string b) {
        int i=0;
        int al = a.length(), bl = b.length();
        int abl = max(al,bl) + 1;
        if(al==0)
            return b;
        if(bl==0)
            return a;
        
        string res(abl,'0');
        int t;
        int by = 0;
        while(al>=1 && bl>=1 && a[al-1]!='\0' && b[bl-1]!='\0'){
            t = int(a[al-1] + b[bl-1] - 96) + by;
            if(t>=2)
                by = 1;
            else 
                by = 0;
                
            res[abl-1] = char(t%2 + 48);
            abl--;
            al--;
            bl--;
        }
        while(al>=1 && a[al-1]!='\0'){
            t = int(a[al-1] - '0') + by;
            if(t>=2)
                by = 1;
            else 
                by = 0;
                
            res[abl-1] = char(t%2 + 48);
            abl--;
            al--;
        }
        while(bl>=1 && b[bl-1]!='\0'){
            t = int(b[bl-1]-'0') + by;
            if(t>=2)
                by = 1;
            else 
                by = 0;
                
            res[abl-1] = char(t%2 + 48);
            abl--;
            bl--;
        }
        if(by==1)
            res[abl-1] = '1';
        else
            res.erase(0,1);
            
        return res;
    }
};