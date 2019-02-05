/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
Space: O(1)

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       
        int rows = matrix.size(); if(rows == 0) return;
        int cols = matrix[0].size(); if(cols == 0) return;
        
        bool firstRowZero = false;
        bool firstColZero = false;
        
        for(int i = 0; i < rows; i++)
            if(matrix[i][0] == 0)
                firstColZero = true;
            
        for(int i = 0; i < cols; i++)
            if(matrix[0][i] == 0)
                firstRowZero = true;
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0; //col j must be zero
                    matrix[i][0] = 0; // row i must be zero;
                }
            }
        }
        
        for(int i = rows-1; i >=1; i--){
            for(int j = cols-1; j >= 1; j--){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if(firstRowZero){
            for(int i = 0; i < cols; i++)
                matrix[0][i] = 0;
        }
        if(firstColZero){
            for(int  i = 0; i < rows; i++)
                matrix[i][0] = 0;
        }
    }
};