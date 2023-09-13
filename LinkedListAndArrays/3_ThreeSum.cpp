// https://leetcode.com/problems/3sum/

#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
      if (i > 0 && nums.at(i - 1) == nums.at(i)) {
        continue;
      }

      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int num = nums.at(i) + nums.at(j) + nums.at(k);
        if (num == 0) {
          res.push_back({nums.at(i), nums.at(j), nums.at(k)});
          j++;
          while (j < k && nums.at(j - 1) == nums.at(j)) {
            j++;
          }
        } else if (num < 0)
          j++;
        else
          k--;
      }
    }

    return res;
  }
};