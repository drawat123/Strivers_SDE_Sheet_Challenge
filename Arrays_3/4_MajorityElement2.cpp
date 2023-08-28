#include <limits>
#include <vector>

class Solution {
public:
  std::vector<int> majorityElement(std::vector<int> &nums) {
    int num1 = std::numeric_limits<int>::min(), num2 = num1,
        n = nums.size() / 3;
    int count1 = 0, count2 = 0;
    std::vector<int> res;
    for (const int &num : nums) {
      if (count1 == 0 && num2 != num) {
        num1 = num;
        count1 = 1;
      } else if (count2 == 0 && num1 != num) {
        num2 = num;
        count2 = 1;
      } else if (num1 == num)
        count1++;
      else if (num2 == num)
        count2++;
      else {
        count1--;
        count2--;
      }
    }

    count1 = 0, count2 = 0;
    for (auto num : nums) {
      if (num1 == num)
        count1++;
      if (num2 != num1 && num2 == num)
        count2++;
    }
    if (count1 > n)
      res.push_back(num1);

    if (count2 > n)
      res.push_back(num2);

    return res;
  }
};

int main() {
  std::vector<int> nums = {2, 1, 1, 3, 1, 4, 5, 6};
  Solution s;
  s.majorityElement(nums);

  return 0;
}