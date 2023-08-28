#include <iostream>
#include <vector>

class Solution {
private:
  int helperFunction(int b, int r, int m, int n,
                     std::vector<std::vector<int>> &matrix) {
    if (b == m || r == n) {
      return 0;
    }
    if (b == m - 1 && r == n - 1) {
      return 1;
    }
    if (matrix[b][r] != -1) {
      return matrix[b][r];
    }

    matrix[b][r] = helperFunction(b, r + 1, m, n, matrix) +
                   helperFunction(b + 1, r, m, n, matrix);
    return matrix[b][r];
  }

public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));
    helperFunction(0, 0, m, n, matrix);
    return (m == 1 && n == 1) ? 1 : matrix[0][0];
  }
};

int main() {
  Solution s;
  int m = 2, n = 2;
  std::cout << s.uniquePaths(m, n) << '\n';
}