class Solution {
public:
    string lcp(vector<string>& a, int begin, int end){
    if(begin == end)
        return a[begin];
    string r="";
    int mid = (begin+end)/2;
    string r1 = lcp(a, begin, mid);
    string r2 = lcp(a, mid+1, end);
    int i = (int)r1.length();
    int j = (int)r2.length();
    int m=0;
    while(m!=i && m!=j){
        if(r1[m] == r2[m]){
            r += r1[m];
            m++;
        }
        else
            break;
    }
    //cout<<"begin:"<<begin<<"end:"<<end<<"r:"<<r<<"r1:"<<r1<<"r2:"<<r2<<endl;
    return r;
}
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        else
            return lcp(strs, 0, (int)strs.size()-1);
}
};