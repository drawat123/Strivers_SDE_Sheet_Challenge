// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include <algorithm>
#include <iostream>

struct Item {
  int value;
  int weight;
};

class Solution {
public:
  double fractionalKnapsack(int W, Item arr[], int n) {
    double res = 0;

    std::sort(arr, arr + n, [](const Item &i1, const Item &i2) {
      return (static_cast<double>(i1.value) / i1.weight) >
             (static_cast<double>(i2.value) / i2.weight);
    });

    for (int i = 0; i < n && W > 0; i++) {
      int maxWeight = std::min(W, arr[i].weight);

      res += (static_cast<double>(arr[i].value) * maxWeight) / arr[i].weight;

      W -= maxWeight;
    }

    return res;
  }
};

int main() {
  Solution s;
  int N = 3, W = 30;
  Item arr[] = {{120, 30}, {100, 20}, {60, 10}};
  std::cout << s.fractionalKnapsack(W, arr, N);

  return 0;
}