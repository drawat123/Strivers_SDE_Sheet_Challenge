#include <vector>

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int l = 0, r = matrix.size() - 1, rowIdx = r;
    while (l <= r) {
      int m = (l + r) / 2;
      if (target == matrix[m][0])
        return true;
      else if (target < matrix[m][0])
        rowIdx = r = m - 1;
      else
        l = m + 1;
    }
    if (rowIdx == -1)
      return false;

    l = 0;
    r = matrix[rowIdx].size() - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (matrix[rowIdx][m] == target)
        return true;
      else if (matrix[rowIdx][m] < target)
        l = m + 1;
      else
        r = m - 1;
    }

    return false;
  }
};

// 1 10 23 50 75 80 95, target = 9