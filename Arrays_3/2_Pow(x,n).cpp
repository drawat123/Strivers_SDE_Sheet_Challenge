#include <iostream>
#include <limits>

class Solution {
public:
  double myPowBruteForce(double x, int n) {
    double res = 1;
    unsigned int nUInt = std::abs(n);
    if (n != 0 && std::abs(x) != 1) {
      for (unsigned int i = 0; i < nUInt; i++)
        res *= x;
      if (n < 0 && res)
        res = 1 / res;
    } else if (x == -1)
      res = nUInt % 2 == 0 ? 1 : -1;

    return res;
  }
  double myPow(double x, int n) {
    double res = 1;
    unsigned int nUInt = std::abs(n);
    while (nUInt > 0) {
      if (nUInt % 2 == 0) {
        x *= x;
        nUInt /= 2;
      } else {
        res *= x;
        nUInt--;
      }
    }
    res = n < 0 ? (1 / res) : res;
    return res;
  }
};

int main() {
  Solution s;
  std::cout << s.myPow(2.00000, 10) << '\n';
  std::cout << s.myPow(2.10000, 3) << '\n';
  std::cout << s.myPow(2.00000, -2) << '\n';
  std::cout << s.myPow(2.00000, -2147483648) << '\n';
  std::cout << s.myPow(1.00000, -2147483648) << '\n';
  std::cout << s.myPow(1.0000000000001, -2147483648) << '\n';
}