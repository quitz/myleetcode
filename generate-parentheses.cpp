typedef char data;
#define max 50

map<char, char> bra= {
    {'(',')'},
    {')','('},
    {'{','}'},
    {'}','{'},
    {'[',']'},
    {']','['}
};
class Solution{
public:
    class stack{
    private:
        int top;
        data res[10];
    public:
        stack():top(-1){};
        ~stack();
        bool push(data a){
            if(top == max-1)
                return false;
            else
                res[++top] = a;
            return true;
        }
        bool pop(data &a){
            if(top == -1){
                a = 'x';
                return false;
            }
            else
                a = res[top--];
            return true;
        }
        void clear(){
            top =-1;
        }
        bool isEmpty(){
            return top<0?true:false;
        }
        bool isFull(){
            return top>max?true:false;
        }
    };
    int isValid(string s) {
        stack *t = new stack();
        bool r = false;
        int res =0;
        int l = s.length();
        char temp;
        for(int i=0;i<l;i++)
        {
            if(s[i] == '('){
                t->push(s[i]);
                res++;
            }
            else{
                res--;
                t->pop(temp);
                
                if (temp == '(')
                    continue;
                else
                    return -1;
                
            }
        }
        
        //r = t->isEmpty();
        return res;
    }
    bool isSat(string s) {
        stack *t = new stack();
        bool r = true;
        int l = s.length();
        char temp;
        for(int i=0;i<l;i++)
        {
            if(s[i] == '(')
                t->push(s[i]);
            else{
                t->pop(temp);
                if (temp == '(')
                    continue;
                else
                    return false;
                
            }
        }
        
        //r = t->isEmpty();
        return r;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> a;
        string b="";
        a.push_back(b);
        string c="()";
        //dfs(0, 2*n, b, a);
        for(int i=0;i<2*n;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<a.size();k++){
                    string t = a[k] + c[j];
                    if(isValid(t))
                        a.push_back(t);
                }
            }
        }
        return a;
    }
    vector<string> generateParenthesis1(int n) {
        vector<string> a;
        string b="";
        dfs(0, 2*n, b, a);
        return a;
    }
    
    void dfs(int index, int mdeep, string ans, vector<string> &res){
        if(index == mdeep){
            if(isValid(ans)==0)
                res.push_back(ans);
            return;
        }
        string use = "()";
        for(int i=0;i<2;i++){
            string check = ans + use[i];
            if(isValid(check)>=0)
                dfs(index+1, mdeep, check, res);
        }
        
    }
};