/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int upIndex = 0, downIndex = matrix.size()-1;
        
        while(upIndex < downIndex){
            for(int i = 0; i < matrix[upIndex].size(); i++)
                swap(matrix[upIndex][i],matrix[downIndex][i]);
            upIndex++; downIndex--;
        }
        
        for(int i = 0; i < matrix.size(); i++)
            for(int j = i+1; j < matrix.size(); j++)
                swap(matrix[i][j],matrix[j][i]);
    }
};