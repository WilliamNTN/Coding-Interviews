//A robot is located at the top-left corner of a m x n grid

//The robot can only move either down or right at any point in time.
//The robot is trying to reach the bottom-right corner of the grid

//How many possible unique paths are there?

class Solution {
public:
    long long int** memory;
    
    
    long long int count(int a, int b, int m, int n){
        if(a == m && b == n) return 1;
        if(a > m || b > n) return 0;
        
        if(memory[a][b] != -1)
            return memory[a][b];
        
        return memory[a][b] = count(a+1,b,m,n) + count(a,b+1,m,n);
    }
    long long int uniquePaths(int m, int n) {
        if(n==0 || m==0) return 0;        
        
        memory = (long long int**)malloc(sizeof(long long int*)*(m));
        for(int i = 0; i<m; i++)
            memory[i] = (long long int*)malloc(sizeof(long long int)*n);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                memory[i][j] = -1;
            }
        }
        return count(0,0,m-1,n-1);
    }
};