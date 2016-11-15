class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        stack<int> s;
        int t1,t2;
        string a = "+";
        string m = "-";
        string p = "*";
        string t = "/";
        for(int i=0;i<len;i++){
            if(tokens[i] == a){
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                s.push(t1+t2);
            }
            else if(tokens[i] == m){
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                s.push(t2-t1);
            }
            else if(tokens[i] == p){
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                s.push(t1*t2);
            }
            else if(tokens[i] == t){
                t1 = s.top();
                s.pop();
                t2 = s.top();
                s.pop();
                if(t1 == 0)
                    s.push(0);
                else
                    s.push(t2/t1);
            }
            else{
                int number = stoi(tokens[i]);
                s.push(number);
            }
        }
        return s.top();
        
    }
};