class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int row = board.size();
        if(row == 0)return false;
        const int col = board[0].size();
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(board[i][j] == word[0] && dfs(i,j,word,0,board))
                    return true;
        return false;
    }
    bool dfs(int i, int j, string word, int index, vector<vector<char>> &board){
        if(index==word.length()-1)
            return true;
        /*if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || use[i][j] || board[i][j]!=word[index])
            return false;*/
        char u = board[i][j];
        board[i][j] = '#';
        
        if(i-1>=0 && board[i-1][j] == word[index+1])
            if(dfs(i-1,j,word,index+1,board))
                return true;
                
        if(i+1<board.size() && board[i+1][j] == word[index+1])
            if(dfs(i+1,j,word,index+1,board))
                return true;
        
        if(j-1>=0 && board[i][j-1] == word[index+1])
            if(dfs(i,j-1,word,index+1,board))
                return true;
                
        if(j+1<board[0].size() && board[i][j+1] == word[index+1])    
            if(dfs(i,j+1,word,index+1,board))
                return true;
        
        board[i][j] = u;
        return false;
        
    }
    
};