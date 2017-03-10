class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;
        for(int i=expression.size()-1;i>=0;i--){
            char c = expression[i];
            if(!s.empty() && s.top() == '?'){
                s.pop();
                char c1 = s.top();
                s.pop();
                s.pop();
                char c2 = s.top();
                s.pop();
                if(c == 'T')
                    s.push(c1);
                else
                    s.push(c2);
            }
            else{
                s.push(c);
            }
            
        }
        string ret(1,s.top());
        return ret;
    }
};