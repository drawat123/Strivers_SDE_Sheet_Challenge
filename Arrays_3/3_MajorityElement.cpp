#include <vector>

class Solution {
public:
  int majorityElement(std::vector<int> &nums) {
    int mElement = 0, cnt = 0;
    for (const int &num : nums) {
      if (cnt == 0) {
        mElement = num;
        cnt = 1;
      } else if (num != mElement)
        cnt--;
      else
        cnt++;
    }

    cnt = 0;
    for (const int &num : nums) {
      if (num == mElement)
        cnt++;
    }

    return cnt > nums.size() / 2 ? mElement : -1;
  }
};