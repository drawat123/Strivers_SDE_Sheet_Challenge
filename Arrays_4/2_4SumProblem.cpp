#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    int n = nums.size();
    for (int i = 0; i < (n - 3); i++) {
      if (i > 0 && nums[i - 1] == nums[i])
        continue;

      for (int j = i + 1; j < (n - 2); j++) {
        if (j != i + 1 && nums[j - 1] == nums[j])
          continue;

        int k = j + 1, l = n - 1;
        while (k < l) {
          long num =
              (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l];
          if (num == target) {
            res.push_back({nums[i], nums[j], nums[k], nums[l]});
            k++;
            while (nums[k - 1] == nums[k] && k < l)
              k++;
          } else if (num < target)
            k++;
          else
            l--;
        }
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {-3, -1, 0, 2, 4, 5};
  int target = 2;
  s.fourSum(nums, target);

  return 0;
}