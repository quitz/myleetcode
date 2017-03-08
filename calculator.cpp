class Solution{
  public:
    int calculator(string str){
        map<char,int> pri;
        pri['^'] = 3;
        pri['*'] = 2, pri['/'] = 2;
        pri['+'] = 1, pri['-'] = 1;

        stack<char> num, sym;

        int val = 0;
        for(int i=0;i<str.size();i++){
            if(str[i]>='0' && str[i]<='9')      //number
                val = val*10 + (str[i] - '0');
            else if(str[i] == ' ')
                continue;

            else{
                if(sym.empty()){
                    sym.push(str[i]);
                    num.push(val);
                }
                else if(pri[sym.top()] < pri[str[i]]){
                    sym.push(str[i]);
                    num.push(val);
                }
                else{           //current operator has a lower priority
                    int num2 = val, num1 = num.top();
                    num.pop();
                    char op = sym.top();
                    sym.pop();
                    if(op == '+')
                        num1 += num2;
                    else if(op == '-')
                        num1 -= num2;
                    else if(op == '*')
                        num1 *= num2;
                    else if(op == '/')
                        num1 /= num2;
                    else
                        num1 = pow(num1,num2);

                    num.push(num1);
                    sym.push(str[i]);
                }
                val = 0;
            }
        }
        num.push(val);

        while(!sym.empty()){
            int num2 = num.top();num.pop();
            int num1 = num.top();num.pop();
            char op = sym.top();
                    sym.pop();
                    if(op == '+')
                        num1 += num2;
                    else if(op == '-')
                        num1 -= num2;
                    else if(op == '*')
                        num1 *= num2;
                    else if(op == '/')
                        num1 /= num2;
                    else
                        num1 = pow(num1,num2);
            num.push(num1);
        }

        return num.top();

    }
}