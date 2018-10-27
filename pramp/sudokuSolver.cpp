
// Given an 2D char array, representing a 9x9 sudoku board,
// where cells may be filled with chars from "1" to "9", or
// "." representing an empty cell, returns if it's possible to
// solve the sudoku, or false if it's impossible to complete given
// the already filled cells.

//The approach is to complete all the board by backtracking, return true if this
// is possible or false if its not. For this, the recursive algorithm starts
// by passing through all empty cells, filling it with a possible number.
// If no number is possible, return a step and change the value of a previous
// filled cell. It will return false if there is no answer.

#include <iostream>
#include <vector>

using namespace std;

bool isOk(vector<vector<char>> &board, int row, int col, char t){
    for(int i = 0; i<9; i++){
      if(board[row][i] == t) return false;
      if(board[i][col] == t) return false;
    }

    int startRow = (row/3)*3;
    int startCol = (col/3)*3;

    for(int i = startRow; i < startRow+3; i++){
      for(int j = startCol; j < startCol+3; j++){
        if(board[i][j] == t) return false;
      }
    }

    return true;
}
bool solve(vector<vector<char>> &board, int row, int col){

  if(row > 8){
    return true;
  }

  int nextrow, nextcol;
  if(col == 8){
    nextrow = row+1;
    nextcol = 0;
  }else{
    nextrow = row;
    nextcol = col+1;
  }

  if(board[row][col] != '.') // if its already filled up
    return solve(board,nextrow,nextcol);

  for(int i = 1; i<=9; i++){
    char c = (i - '0');   // int to char

    if(isOk(board,row,col,c)){
      board[row][col] = c;
      if(solve(board,nextrow,nextcol) == true)
        return true;
    }
  }
  return false;
}

bool sudokuSolve( const vector<vector<char>>& board ) {

  vector<vector<char>> newOne( board.begin(),board.end());
  return solve(newOne,0,0);
}

int main() {

  return 0;
}
