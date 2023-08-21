#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> res;

    std::sort(intervals.begin(), intervals.end());

    for (const auto &vec : intervals) {
      if (res.empty() || vec[0] > res.back()[1])
        res.push_back(vec);
      else
        res.back()[1] = std::max(res.back()[1], vec[1]);
    }

    return res;
  }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> intervals = {{8, 10}, {2, 6}, {1, 3}, {15, 18}};

  s.merge(intervals);

  return 0;
}