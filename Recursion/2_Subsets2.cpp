// https://leetcode.com/problems/subsets-ii/description/

#include <algorithm>
#include <set>
#include <vector>

class Solution {
private:
  void helper(int idx, std::vector<int> &arr, std::vector<int> tempArr,
              std::vector<std::vector<int>> &res) {
    for (int i = idx; i < arr.size(); i++) {
      if (i != idx && arr[i] == arr[i - 1]) {
        continue;
      }
      tempArr.push_back(arr[i]);
      helper(i + 1, arr, tempArr, res);
      tempArr.pop_back();
    }

    res.push_back(tempArr);
  }

public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> res;

    helper(0, nums, {}, res);

    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {1, 2, 2};
  s.subsetsWithDup(nums);

  return 0;
}