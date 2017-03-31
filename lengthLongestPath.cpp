class Solution {
public:
    int lengthLongestPath(string input) {
        int ret = 0;
        stack<int> s1, s2,s3;
        
        int i = 0;
        int dir = 1;
        while( i<input.length() && input[i] != '\n' ){
            i++;
            if(input[i] == '.')
                dir = 0;
        }
        s1.push(0);
        s2.push(i);
        s3.push(dir);
        ret += i;
        //cout<<"line 12 "<<ret<<endl; 
        int s_max = 0;
        
        for(i = 0;i<input.length();i++){
            if(input[i] == '\n'){
                i += 1; //\n
                int layer = 0;
                
                while(i<input.length() && input[i] == '\t'){
                    i+=1;
                    layer++;
                }
                int j = i;
                int isDir = 1;
                
                while(j<input.length() && input[j] != '\n'){
                    j++;
                    if(input[j] == '.')
                        isDir = 0;
                }
                
                int tmp = j-i+1; //+1 represents /
                if(layer == 0)
                    tmp--;
                //cout<<"line 28 "<<j<<" "<<i<<" "<<tmp<<endl;
                if(s1.empty()){
                    s1.push(layer);
                    s2.push(tmp);
                    s3.push(isDir);
                }
                
                else{
                    if(s1.top() < layer){
                        s1.push(layer);
                        s2.push(s2.top() + tmp);
                        s3.push(isDir);
                    }
                    
                    else{ //s1.top() >= layer
                        int t = 0;
                        
                        while(!s1.empty() && s1.top() >= layer){
                            t = s2.top();
                            s1.pop();
                            s2.pop();
                            if(s3.top() == 0) //not dir
                                s_max = max(s_max,t);
                            s3.pop();
                        }
                        
                        s1.push(layer);
                        s3.push(isDir);
                        if(s2.empty())
                            s2.push(tmp);
                        else
                            s2.push(s2.top() + tmp);
                    }
                }
                i = j;
                i--;
            }
        }
        if(!s2.empty() && s3.top() != 1)
            s_max =max(s_max,s2.top());
        
        return s_max;
    }
};