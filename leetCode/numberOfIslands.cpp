/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
*/

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i,int j, vector<vector<bool>>& visited){
        visited[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();
        for(int a = -1; a <= 1; a += 2){
            int ni = i;
            int nj = j + a;
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1' && !visited[ni][nj])
                dfs(grid,ni,nj,visited);
            
            ni = i + a;
            nj = j;
            
            if(ni >= 0 && ni < n && nj >= 0 && nj < m &&grid[ni][nj] == '1' && !visited[ni][nj])
                dfs(grid,ni,nj,visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        if(m == 0) return 0;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        
        return ans;
    }
};