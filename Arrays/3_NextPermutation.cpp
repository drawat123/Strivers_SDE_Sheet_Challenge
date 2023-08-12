#include <algorithm>
#include <vector>

class Solution {
public:
  void nextPermutation(std::vector<int> &nums) {
    int idx1 = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        idx1 = i;
        break;
      }
    }

    if (idx1 == -1) {
      std::reverse(nums.begin(), nums.end());
      return;
    }

    for (int i = nums.size() - 1; i > idx1; i--) {
      if (nums[i] > nums[idx1]) {
        std::swap(nums[i], nums[idx1]);
        break;
      }
    }

    std::reverse(nums.begin() + idx1 + 1, nums.end());
  }
};