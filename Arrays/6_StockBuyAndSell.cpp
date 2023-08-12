#include <limits>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    int minPrice = std::numeric_limits<int>::max(), res = 0;
    for (const int &price : prices) {
      if (price < minPrice)
        minPrice = price;
      else
        res = std::max(price - minPrice, res);
    }

    return res;
  }
};

// prices = [7,1,5,3,6,4]