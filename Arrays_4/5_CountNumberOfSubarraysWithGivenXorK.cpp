#include <iostream>
#include <unordered_map>
#include <vector>

int subarraysWithSumK(std::vector<int> a, int b) {
  int xorRes = 0, cnt = 0;
  std::unordered_map<int, int> uMap; // sum,index
  for (int i = 0; i < a.size(); i++) {
    xorRes ^= a[i];
    if (xorRes == b || a[i] == b) {
      cnt++;
    } else {
      auto itr = uMap.find(xorRes);
      if (itr == uMap.end()) {
        uMap[xorRes] = i;
      } else {
        cnt++;
      }
    }
  }

  return cnt;
}

int main() {
  std::vector<int> a = {1, 2, 3, 3};
  int b = 2;
  std::cout << subarraysWithSumK(a, b) << '\n';

  return 0;
}