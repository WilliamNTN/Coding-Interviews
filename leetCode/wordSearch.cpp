class Solution {
public:
    bool dfs(vector<vector<char>> board,int i, int j, string word, int position,vector<vector<bool>> visited){
        if(position == word.size()) return true;
        if(board[i][j] != word[position]) return false;
        visited[i][j] = true;
        int n = board.size();
        int m = board[0].size();
        position++;
        if(position == word.size()) return true;
        for(int  a = -1; a <= 1; a+=2){
            int ni = i + a;
            int nj = j;
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj])
                if(dfs(board,ni,nj,word,position,visited)) return true;
            
            ni = i;
            nj = j+a;
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj])
                if(dfs(board,ni,nj,word,position,visited)) return true;
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size(); if( n== 0) return false;
        int m = board[0].size(); if(m == 0) return false;
        if(word.size() == 0) return true;
            
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(board,i,j,word,0,visited)) return true;
            }
        }
        
        return false;
    }
};