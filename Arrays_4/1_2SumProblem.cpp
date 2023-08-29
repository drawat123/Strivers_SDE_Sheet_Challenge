#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> numsMap;
    std::vector<int> vec;
    for (int i = 0; i < nums.size(); i++) {
      auto itr = numsMap.find(target - nums[i]);
      if (itr == numsMap.end())
        numsMap[nums[i]] = i;
      else {
        vec.push_back(itr->second);
        vec.push_back(i);
        break;
      }
    }
    return vec;
  }
};