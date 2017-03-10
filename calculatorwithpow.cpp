string process(string str){
    string ret;
    while(str.find("^") != string::npos){
        int idx = str.find("^");
        
        int i,j;
        for(i=idx-1;i>=0;i--)
            if(!isdigit(str[i]))
                break;
        i++;
        string t = str.substr(i,idx-i);
        
        for(j=idx+1;j<str.size();j++)
            if(!isdigit(str[j]))
                break;
        string t1 = str.substr(idx+1,j-idx-1);
        
        
        int tmp = pow(stoi(t),stoi(t1));
        string n = to_string(tmp);
        
        str.replace(i,j-i,n);
    }
    return str;
}

int calculate(string str){
    if(str.length() == 0)
        return 0;
    str = process(str);
    stack<int> s;
    char sig = '+';
    int tmp = 0,res=0;
    for(int i=0;i<str.length();i++){
        if(isdigit(str[i]))
            tmp = tmp*10 + str[i] - '0';
        if((!isdigit(str[i]) && str[i]!=' ') || i==str.length() - 1){
            if(sig == '+')
                s.push(tmp);
            else if(sig == '-')
                s.push(-tmp);
            else{
                int num;
                if(sig == '*')
                    num = s.top()*tmp;
                else
                    num = s.top()/tmp;
                s.pop();
                s.push(num);
            }
            sig = str[i];
            tmp = 0;
        }
    }
    while(!s.empty()){
        res += s.top();
        s.pop();
    }
    return res;
}