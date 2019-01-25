/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated
*/

class Solution {
public:
    
    bool validateRowCol(vector<vector<char>>& board, int index){
        set<char> colSet;
        set<char> rowSet;
        
        for(int i = 0; i < board.size(); i++){
            if(board[index][i] != '.'){ //row
                if(rowSet.find(board[index][i]) != rowSet.end())
                    return false;
                rowSet.insert(board[index][i]);
            }
            if(board[i][index] != '.'){ //col
                if(colSet.find(board[i][index]) != colSet.end())
                    return false;
                colSet.insert(board[i][index]);
            }
            
        }
        return true;   
    }
    
    bool validateSquare(vector<vector<char>>& board, int startCol, int startRow){
        int size = sqrt(board.size());
        
        set<char> squareSet;
        for(int i = startCol; i < startCol+size; i++){
            for(int j = startRow; j < startRow+size; j++){
                if(board[i][j] == '.') continue;
                if(squareSet.find(board[i][j]) != squareSet.end()) return false;
                squareSet.insert(board[i][j]);
            }
        }
        
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); i++){
            if(!validateRowCol(board,i)) return false;
        }
        
        int size = sqrt(board.size());
        
        for(int i = 0; i < board.size(); i+=size){
            for(int j = 0; j < board.size(); j+=size){
                if(!validateSquare(board,i,j)) return false;
            }
        }
        
        return true;
        /*
        0 0   0 3  0 6
        3 0   3 3  3 6
        6 0   6 3  6 6
        */
            
    }
};