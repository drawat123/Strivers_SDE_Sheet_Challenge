#include <iostream>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int curMax = nums[0], sumTillNow = curMax;
    for (int i = 1; i < nums.size(); i++) {
      sumTillNow = std::max((sumTillNow + nums[i]), nums[i]);
      curMax = std::max(curMax, sumTillNow);
    }

    return curMax;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {8, -19, 5, -4, 20};
  std::cout << s.maxSubArray(nums) << std::endl;
  return 0;
}

/*
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

curmax = -2
sum = 0
loop from 1 to array length
        sum += curmax + array[i]
        if sum greater than curmax
                curmax = sum
        if array[i] > curmax
                curmax = array[i]
                sum = array[i]
*/