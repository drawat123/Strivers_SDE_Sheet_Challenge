#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> res;
    for (int i = 0; i < numRows; i++) {
      std::vector<int> vec(i + 1, 1);
      for (int j = 1; j < vec.size() - 1; j++)
        vec[j] = res[i - 1][j - 1] + res[i - 1][j];

      res.push_back(vec);
    }

    return res;
  }
};

int main() {
  Solution s;
  s.generate(1);
  s.generate(5);

  return 0;
}