#include <algorithm>
#include <vector>

class Solution {
public:
  void rotate(std::vector<std::vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }

    for (std::vector<int> &vec : matrix)
      std::reverse(vec.begin(), vec.end());
  }
};