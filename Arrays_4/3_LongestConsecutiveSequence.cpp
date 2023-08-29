#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int> &nums) {
    std::unordered_set<int> numsSet(nums.begin(), nums.end());
    int res = 0;

    for (const int &num : numsSet) {
      if (numsSet.find(num - 1) == numsSet.end()) {
        int cnt = 1;
        while (numsSet.find(num + cnt) != numsSet.end()) {
          cnt++;
        }
        res = std::max(res, cnt);
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {1, 3, 5, 2, 4};
  std::cout << s.longestConsecutive(nums) << '\n';
  return 0;
}

/*
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].Therefore
its length is 4.
*/