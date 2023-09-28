#include <algorithm>
#include <string>
#include <vector>

class Solution {
private:
  bool isPalindrome(const std::string &str) {
    std::string temp = str;
    std::reverse(temp.begin(), temp.end());
    return temp == str;
  }

  void helper(int idx, std::string s, std::vector<std::string> &tempArr,
              std::vector<std::vector<std::string>> &res) {
    if (idx == s.size()) {
      res.push_back(tempArr);
      return;
    }

    for (int i = idx; i < s.size(); i++) {
      const std::string &str = s.substr(idx, i - idx + 1);
      if (isPalindrome(str)) {
        tempArr.push_back(str);
        helper(i + 1, s, tempArr, res);
        tempArr.pop_back();
      }
    }
  }

public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    std::vector<std::string> tempArr;
    std::vector<std::vector<std::string>> res;
    helper(0, s, tempArr, res);

    return res;
  }
};

int main() {
  Solution s;
  std::string str = "aab";
  s.partition(str);

  return 0;
}