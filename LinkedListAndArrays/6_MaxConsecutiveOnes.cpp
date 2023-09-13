// https://leetcode.com/problems/max-consecutive-ones/

#include <vector>

class Solution {
public:
  int findMaxConsecutiveOnes(std::vector<int> &nums) {
    int cnt = 0, currMax = 0;
    for (int i = 0; i < nums.size(); i++) {
      currMax = nums[i] ? currMax + 1 : 0;
      cnt = std::max(cnt, currMax);
    }

    return cnt;
  }
};