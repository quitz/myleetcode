class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i=-1,j=-1,dis=INT_MAX;
        for(int k=0;k<words.size();k++){
            if(words[k] == word1){
                i = k;
                if(j!=-1)
                    dis = min(i-j,dis);
            }
            else if(words[k] == word2){
                j = k;
                if(i!=-1)
                    dis = min(j-i,dis);
            }
        }
        return dis;
    }
};