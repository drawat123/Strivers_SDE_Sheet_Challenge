#include <cmath>
#include <numeric>
#include <vector>

std::pair<int, int> missingAndRepeating(std::vector<int> &arr, int n) {
  std::pair<int, int> res{0, 0};
  for (const int &num : arr) {
    int idx = std::abs(num) - 1;
    if (arr[idx] < 0)
      res.second = idx + 1;
    else
      arr[idx] = -1 * arr[idx];
  }

  for (int i = 0; i < n && res.first == 0; i++) {
    // the index at which the element is positive is the missing number
    if (arr[i] > 0)
      res.first = i + 1;
  }

  return res;
}

int main() {
  std::vector<int> arr = {6, 4, 3, 5, 1, 1};
  int n = 6;
  missingAndRepeating(arr, n);

  return 0;
}