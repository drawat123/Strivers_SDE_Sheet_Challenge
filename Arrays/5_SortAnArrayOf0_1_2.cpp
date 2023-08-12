#include <map>
#include <vector>

class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid < high) {
      if (nums[mid] == 0) {
        std::swap(nums[low], nums[mid]);
        mid++;
        low++;
      } else if (nums[mid] == 2) {
        std::swap(nums[high], nums[mid]);
        high--;
      } else
        mid++;
    }
  }
};

int main() {
  Solution s;
  std::vector<int> nums{2, 0, 2, 1, 1, 2};
  s.sortColors(nums);

  return 0;
}