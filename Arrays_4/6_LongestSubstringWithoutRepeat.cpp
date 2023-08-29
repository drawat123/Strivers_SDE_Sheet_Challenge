#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int res = 0;
    std::vector<char> charVec;
    for (const char &ch : s) {
      auto itr = std::find(charVec.begin(), charVec.end(), ch);
      if (itr == charVec.end()) {
        charVec.push_back(ch);
        res = std::max(res, static_cast<int>(charVec.size()));
      } else {
        charVec.erase(charVec.begin(), itr + 1);
        charVec.push_back(ch);
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  std::string str = "pwawkew";
  std::cout << s.lengthOfLongestSubstring(str) << '\n';

  return 0;
}