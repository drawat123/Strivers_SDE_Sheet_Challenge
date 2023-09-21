// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int findPlatform(int arr[], int dep[], int n) {
    std::sort(arr, arr + n);
    std::sort(dep, dep + n);

    int res = 1;
    int count = 1;
    int i = 1, j = 0;
    while (i < n && j < n) {
      if (arr[i] <= dep[j]) {
        count++;
        i++;
      } else {
        count--;
        j++;
      }
      res = std::max(res, count);
    }

    return res;
  }
};

int main() {
  Solution s;

  int n = 6;
  int arr[] = {900, 940, 950, 1100, 1500, 1800};
  int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

  std::cout << s.findPlatform(arr, dep, n);

  return 0;
}