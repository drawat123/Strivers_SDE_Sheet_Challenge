// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int lastUniqueIdx = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        nums[lastUniqueIdx] = nums[i];
        lastUniqueIdx++;
      }
    }

    return lastUniqueIdx;
  }
};

int main() {
  std::vector<int> nums{0, 1, 2, 3, 4, 5, 6};
  Solution s;
  std::cout << s.removeDuplicates(nums) << '\n';

  return 0;
}