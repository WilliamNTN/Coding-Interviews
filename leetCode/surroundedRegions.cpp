/*
Given a 2D board containing 'X' and 'O' (the letter O)
capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/

class Solution {
public:
    
    
    void fill(vector<vector<char>>& board, vector<vector<bool>>& visited){
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
    bool valid(int x, int y, int n, int m){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    
    void bfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y){
        int n = board.size();
        int m = board[n-1].size();
        
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        visited[x][y] = true;
        
        while(q.size()){
            pair<int,int> position = q.front();
            q.pop();
            x = position.first;
            y = position.second;
            for(int a = -1; a <= 1; a+=2){ 
                int nx = x+a;
                int ny = y;
                if(valid(nx,ny,n,m) && !visited[nx][ny] && board[nx][ny] == 'O'){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
                
                nx = x;
                ny = y+a;
                if(valid(nx,ny,n,m) && !visited[nx][ny] && board[nx][ny] == 'O'){
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
                
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(); if(n == 0) return;
        int m = board[0].size(); if(m == 0) return;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++){
            if(board[i][0]=='O' && !visited[i][0]){
                bfs(board,visited,i,0);
            }
            if(board[i][m-1]=='O' && !visited[i][m-1]){
                bfs(board,visited,i,m-1);
            }
        }
        
        for(int i = 0; i < m; i++){
            if(board[0][i]=='O' && !visited[0][i]){
                bfs(board,visited,0,i);
            }
            if(board[n-1][i]=='O' && !visited[n-1][i]){
                bfs(board,visited,n-1,i);   
            }
        }
        
        fill(board,visited);
    }
};