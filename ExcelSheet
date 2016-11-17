class Solution {
public:
    string convertToTitle(int n) {
        if(n==0)
            return "";
        stack<int> r;
        string res="";
        int i=n,j;
        
        while(i>0){
            int t = i;
            i = i/26;
            j = t%26;
            if(j==0){
                j= 26;
                i = i-1;
            }
            r.push(j);
        }
        
        while(!r.empty()){
            int t;
            //cout<<"line18 "<<t<<endl;
            t = r.top();
            r.pop();
            res.push_back('A' + t - 1);
        }
        return res;
    }
};c