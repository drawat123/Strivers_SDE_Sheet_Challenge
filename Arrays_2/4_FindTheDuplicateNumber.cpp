#include <cmath>
#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int> &nums) {
    for (const int &num : nums) {
      int idx = std::abs(num);
      if (nums[idx] < 0)
        return idx;

      nums[idx] = -1 * nums[idx];
    }

    return 0;
  }
};

/*
Input: nums = [1,3,4,2,2]
Output: 2
*/