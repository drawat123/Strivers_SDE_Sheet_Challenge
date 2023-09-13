// https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>

class Solution {
public:
  int trap(std::vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right) {
      if (height[left] <= height[right]) {
        if (height[left] >= maxLeft) {
          maxLeft = height[left];
        } else {
          res += maxLeft - height[left];
        }
        left++;
      } else {
        if (height[right] >= maxRight) {
          maxRight = height[right];
        } else {
          res += maxRight - height[right];
        }
        right--;
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> height{4, 2, 0, 3, 2, 5};
  std::cout << s.trap(height) << '\n';

  return 0;
}