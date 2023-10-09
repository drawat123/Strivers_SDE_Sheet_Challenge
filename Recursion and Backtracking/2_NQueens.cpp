// https://leetcode.com/problems/n-queens/

#include <string>
#include <vector>

class Solution {
private:
  bool isAvailable(int row, int col, std::vector<std::string> &tempArr) {
    int n = tempArr.size();
    for (int i = 0; i < n; ++i) {
      int diag2 = row - i;
      int diag3 = col + i;
      int diag4 = col - i;

      // row and col
      if (tempArr[row][i] == 'Q' || tempArr[i][col] == 'Q') {
        return false;
      }
      // top left and top right
      if (diag2 >= 0 && diag2 < n) {
        if (diag4 >= 0 && diag4 < n && tempArr[diag2][diag4] == 'Q') {
          return false;
        }
        if (diag3 >= 0 && diag3 < n && tempArr[diag2][diag3] == 'Q') {
          return false;
        }
      }
    }

    return true;
  }

  void helper(int row, std::vector<std::string> tempArr,
              std::vector<std::vector<std::string>> &res) {
    if (row == tempArr.size()) {
      res.push_back(tempArr);
      return;
    }

    for (int col = 0; col < tempArr.size(); col++) {
      if (isAvailable(row, col, tempArr)) {
        tempArr[row][col] = 'Q';
        helper(row + 1, tempArr, res);
        tempArr[row][col] = '.';
      }
    }
  }

public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> tempArr(n, std::string(n, '.'));

    helper(0, tempArr, res);

    return res;
  }
};

int main() {
  Solution s;
  s.solveNQueens(4);

  return 0;
}