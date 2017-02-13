class Solution {
public:
    bool isStrobogrammatic(string num) {
        string t;
        for(int i=0;i<num.length();i++){
            if(num[i] == '1' || num[i]=='8' || num[i] == '0')
                t = num[i] + t;
            else if(num[i] == '6')
                t = '9' + t;
            else if(num[i] == '9')
                t = '6' + t;
            else
                return false;
        }
        return num == t;
    }
};