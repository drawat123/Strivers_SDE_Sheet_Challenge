#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    std::unordered_set<int> setRows;
    std::unordered_set<int> setColumns;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0) {
          setRows.insert(i);
          setColumns.insert(j);
        }
      }
    }

    for (const auto &r : setRows)
      std::fill(matrix[r].begin(), matrix[r].end(), 0);

    for (const auto &c : setColumns) {
      for (int i = 0; i < n; i++)
        matrix[i][c] = 0;
    }
  }
};

int main() {
  std::vector<std::vector<int>> matrix{
      {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  Solution s;
  s.setZeroes(matrix);

  for (auto &vec : matrix) {
    for (auto &num : vec) {
      std::cout << num << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}