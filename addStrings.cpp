class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length(), len2 = num2.length();
        
        if(len1 > len2){
           string t(len1-len2,'0');
           num2 = t + num2;
        }
        else if(len1 < len2){
           string t(len2-len1,'0');
           num1 = t + num1;
        }
        int a=0;
        string ret(num1.length()+1,' ');
        for(int i=num1.length()-1;i>=0;i--){
            int t = (num1[i] - '0') + (num2[i] - '0') + a; 
            if(t>=10){
                a = 1;
                t -=10;
            }
            else
                a = 0;
            
            ret[i+1] = t+'0';
        }
        if(a == 0)
            ret = ret.substr(1);
        else
            ret[0]='1';
        return ret;
    }
};