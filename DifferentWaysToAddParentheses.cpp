class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int len = input.length();
        
        for(int i=0;i<len;i++){
            if(input[i] == '+' || input[i]== '*' || input[i] == '-'){
                vector<int> t1 = diffWaysToCompute(input.substr(0,i));
                vector<int> t2 = diffWaysToCompute(input.substr(i+1));
                
                for(int m=0;m<t1.size();m++){
                    for(int n=0;n<t2.size();n++){
                        if(input[i] == '+')
                            res.push_back(t1[m] + t2[n]);
                        else if(input[i] == '*')
                            res.push_back(t1[m] * t2[n]);
                        else 
                            res.push_back(t1[m] - t2[n]);
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(stoi(input));
        return res;
    }
};