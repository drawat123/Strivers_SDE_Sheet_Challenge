// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class Solution {
private:
  void helper(int n, std::string s, std::string tempStr,
              std::vector<std::string> &dict, std::vector<std::string> &res) {
    for (int i = 1; i <= n; i++) {
      std::string prefix = s.substr(0, i);
      if (std::find(dict.begin(), dict.end(), prefix) != dict.end()) {
        if (i == n) {
          tempStr += prefix;
          res.push_back(tempStr);
          return;
        }
        helper(n - i, s.substr(i, n - i), tempStr + prefix + " ", dict, res);
      }
    }
  }

public:
  std::vector<std::string> wordBreak(int n, std::vector<std::string> &dict,
                                     std::string s) {
    std::vector<std::string> res;
    helper(s.size(), s, "", dict, res);

    return res;
  }
};

int main() {
  Solution s;
  int n = 5;
  std::vector<std::string> dict = {"ca", "ts", "s"};
  std::string str = "cats";
  s.wordBreak(n, dict, str);

  return 0;
}