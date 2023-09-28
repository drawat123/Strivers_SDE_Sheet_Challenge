// https://leetcode.com/problems/combination-sum/

#include <numeric>
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
      helper(idx, target - candidates[idx], tempArr, candidates, res);
      tempArr.pop_back();
    }

    helper(idx + 1, target, tempArr, candidates, res);
  }

public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    std::vector<std::vector<int>> res;
    std::vector<int> tempArr;
    helper(0, target, tempArr, candidates, res);

    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  s.combinationSum(candidates, target);

  return 0;
}