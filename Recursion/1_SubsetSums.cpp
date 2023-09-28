// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

#include <iostream>
#include <vector>

class Solution {
private:
  void helper(int idx, int sum, std::vector<int> &arr, std::vector<int> &res) {
    if (idx == arr.size()) {
      res.push_back(sum);
      return;
    }

    helper(idx + 1, sum + arr[idx], arr, res);
    helper(idx + 1, sum, arr, res);
  }

public:
  std::vector<int> subsetSums(std::vector<int> arr, int N) {
    std::vector<int> res;
    helper(0, 0, arr, res);

    return res;
  }
};

int main() {
  Solution s;
  std::vector<int> arr = {5, 2, 1};
  int N = 3;
  s.subsetSums(arr, N);

  return 0;
}

/*
Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8

 : 0
5: 5
2: 2
1: 1
5 2: 7
5 1: 6
2 1: 3
5 2 1: 8
*/