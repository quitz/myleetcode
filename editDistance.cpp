class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int len1 = word1.length(), len2 = word2.length();
        if(len1==0)
            return len2;
        if(len2==0)
            return len1;
        vector<int> res1(len2,0);
        vector<vector<int>> res(len1,res1);
        int flag=0; 
        
        for(int j=0;j<len2;j++){
            if(word1[0] == word2[j] && flag==0)
                flag=1;;
                
            res[0][j]= j+1-flag;
        }
        flag = 0;
        
        for(int i=0;i<len1;i++){
            if(word1[i] == word2[0] && flag==0)
                flag=1;
                
            res[i][0]= i+1-flag;
        }
        
        /*for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                cout<<res[i][j]<<' ';
            }
            cout<<endl;
        }*/
        
        for(int i=1;i<len1;i++){
            for(int j=1;j<len2;j++){
                if(word1[i] == word2[j])
                    res[i][j] = res[i-1][j-1];
                else{
                    res[i][j] = findMin(res[i-1][j-1],res[i-1][j],res[i][j-1]) + 1;
                }
            }
        }
        return res[len1-1][len2-1];
    }
    int findMin(int a,int b, int c){
        if(a<=b){
            if(a<=c){
                return a;
            }
            return c;
            
        }
        else{
            if(b<=c)
                return b;
            else
                return c;
        }
    }
};