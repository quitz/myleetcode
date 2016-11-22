class Solution {
public:
    string largestNumber(vector<int>& num) {
        vector<string> arr;
        for(auto i:num)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string res;
        for(auto s:arr)
            res+=s;
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return  res;
    }
        /*int len = nums.size();
        if(len == 0)
            return "";
        if(len == 1)
            return to_string(nums[0]);
        
        map<int, int> re;
        map<int, int> nu;
        string res;
        int t = *max_element(nums.begin(),nums.end());
        int tt = cal(t);
        
        
        for(int i=0;i<len;i++){
            
            if(nums[i] == t || cal(nums[i]) == tt){
                re[nums[i]] = nums[i];
                nu[nums[i]]++;
                continue;
            }
            int temp = cal(nums[i]);
            int ys = yushu(nums[i]);
            int k = nums[i];
            for(int j=1;j<=tt-temp;j++){
                nums[i] = nums[i]*10 + ys; 
            }
            
            re[nums[i]] = k;
            nu[k]++ ;
        }
        
        for(auto it = re.rbegin();it!=re.rend();it++){
            for(int i=0;i<nu[it->second];i++)
                res += to_string(it->second);
        }
        
        if(res[0] == '0']
            return "0";
        return res;
        
    }
    
    int cal(int a){
        if(a<=0)
            return 0;
        int r = 1;
        while(a/10>0){
            r++;
            a /= 10;
        }
        return r;
    }
    
    int yushu(int a){
        if(a==0)
            return 0;
        string str = to_string(a);
        return str[str.size()-1]-'0';
    }*/
};