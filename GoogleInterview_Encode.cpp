int main()
{
    cout<<"input a string:"<<endl;
    string s,r,t,ta,tb;
    cin>>s;
    
    stack<char> st;
    int i=0;
    for(i=0;i<s.size();i++){
        
        if(s[i]!=']')
            st.push(s[i]);
        
        else{
            t = "";
            ta = "";
            while(st.top()!='['){
                char te = st.top();
                st.pop();
                ta.push_back(te);
            }
            st.pop();
            int n=0;
            vector<int> tt;
            while(!st.empty() && st.top()>='0' && st.top()<='9'){
                tt.push_back(st.top()-'0');
                st.pop();
            }
            //cout<<"line202"<<endl;
            for(int k = 0; k < tt.size(); k++){
                n += tt[k] * pow(10,k);
                //cout<<tt[k]<<" ";
            }
            
            for(int j=0;j<n;j++)
                t = t + ta;
            
            for(int j=0;j<t.size();j++)
                st.push(t[j]);
        }
    }
    t = "";
    while(!st.empty()){
        t += st.top();
        st.pop();
    }
    
    cout<<t<<endl;
    
}