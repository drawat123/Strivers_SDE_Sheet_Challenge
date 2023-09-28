#include <algorithm>
#include <vector>

class Solution {
private:
  void helper(int idx, int target, std::vector<int> &tempArr,
              std::vector<int> &candidates,
              std::vector<std::vector<int>> &res) {
    if (idx == candidates.size()) {
      if (target == 0) {
        res.push_back(tempArr);
      }
      return;
    }

    if (candidates[idx] <= target) {
      tempArr.push_back(candidates[idx]);
      helper(idx + 1, target - candidates[idx], tempArr, candidates, res);
      tempArr.pop_back();
    }

    while ((idx + 1) < candidates.size() &&
           candidates[idx + 1] == candidates[idx]) {
      idx++;
    }

    helper(idx + 1, target, tempArr, candidates, res);
  }

public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> tempArr;
    std::sort(candidates.begin(), candidates.end());
    helper(0, target, tempArr, candidates, res);

    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> candidates = {2, 5, 2, 1, 2};
  int target = 5;
  s.combinationSum2(candidates, target);

  return 0;
}

/*
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]
*/