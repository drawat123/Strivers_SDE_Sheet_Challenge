#include <iostream>
#include <unordered_map>
#include <vector>

int LongestSubsetWithZeroSum(std::vector<int> arr) {
  int sum = 0, res = 0;
  std::unordered_map<int, int> uMap; // sum, index
  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if (sum == 0) {
      res = std::max(res, i + 1);
    } else {
      auto itr = uMap.find(sum);
      if (itr == uMap.end()) {
        uMap[sum] = i;
      } else {
        res = std::max(res, i - itr->second);
      }
    }
  }

  return res;
}

int main() {
  std::vector<int> arr = {1, -1, 2, -2};
  std::cout << LongestSubsetWithZeroSum(arr) << '\n';
  return 0;
}

/*
Input: [1 -1 2 -2]
Output: 4
*/