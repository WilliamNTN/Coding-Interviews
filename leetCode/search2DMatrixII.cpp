/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

*/

class Solution {
public:
    
    bool valid(int row, int col, int n, int m){
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); if(n == 0) return false;
        int m = matrix[0].size(); if( m== 0) return false;
        
        
        int row = 0, col = m-1;
        
        while(valid(row,col,n,m)){
            if(matrix[row][col] == target) return true;
            if(matrix[row][col] > target) col--;
            else row++;
        }
        
        return false;
    }
};