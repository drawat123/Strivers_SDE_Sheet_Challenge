// https://leetcode.com/problems/sudoku-solver/description/

#include <string>
#include <vector>

class Solution {
private:
  bool isAvailable(char val, int row, int col,
                   std::vector<std::vector<char>> &board) {
    for (int i = 0; i < 9; ++i) { // row and col
      if (board[row][i] == val || board[i][col] == val) {
        return false;
      }
    }

    int minRow = ((row / 3) * 3), minCol = ((col / 3) * 3);
    for (int i = minRow; i <= (minRow + 2); i++) { // sub divison
      for (int j = minCol; j <= (minCol + 2); j++) {
        if (board[i][j] == val) {
          return false;
        }
      }
    }

    return true;
  }

  bool helper(std::vector<std::vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          for (char val = '1'; val <= '9'; val++) {
            if (isAvailable(val, i, j, board)) {
              board[i][j] = val;
              if (helper(board)) {
                return true;
              } else {
                board[i][j] = '.';
              }
            }
          }
          return false;
        }
      }
    }

    return true;
  }

public:
  void solveSudoku(std::vector<std::vector<char>> &board) { helper(board); }
};

int main() {
  Solution s;
  std::vector<std::vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  s.solveSudoku(board);

  return 0;
}