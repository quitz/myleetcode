class Solution{
  public:
    string reverse(string str){
        int i = 0, j = str.size()-1;
        string ret;
        while( j >= 0){
            int tmp = j;
            while(tmp >= 0 && str[tmp] != ' ')
                tmp--;
            ret += str.substr( tmp+1, j-tmp);
            j = tmp;
            while(tmp >=0 && str[tmp] == ' ')
                tmp--;
            ret += str.substr(tmp+1, j-tmp);

            j = tmp;
        }
        return ret;
    }
}