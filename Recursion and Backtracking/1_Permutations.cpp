// https://leetcode.com/problems/permutations/description/

#include <vector>

class Solution {
private:
  void helper(int idx, std::vector<int> &nums,
              std::vector<std::vector<int>> &res) {
    if (idx == nums.size()) {
      res.push_back(nums);
      return;
    }

    for (int i = idx; i < nums.size(); i++) {
      std::swap(nums[i], nums[idx]);
      helper(idx + 1, nums, res);
      std::swap(nums[i], nums[idx]);
    }
  }

public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    helper(0, nums, res);

    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {1, 2, 3};
  s.permute(nums);
}