#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  std::string getPermutation(int n, int k) {
    int fact = 1;
    std::vector<int> numbers;
    std::string res = "";
    k = k - 1;

    for (int i = 1; i < n; i++) {
      numbers.push_back(i);
      fact = fact * i;
    }
    numbers.push_back(n);

    while (true) {
      res += std::to_string(numbers[k / fact]);
      numbers.erase(numbers.begin() + (k / fact));
      if (numbers.size() == 0) {
        break;
      }

      k = k % fact;
      fact = fact / numbers.size();
    }

    return res;
  }
};

int main() {
  Solution s;
  int n = 4, k = 17;
  std::cout << s.getPermutation(n, k) << '\n';

  return 0;
}