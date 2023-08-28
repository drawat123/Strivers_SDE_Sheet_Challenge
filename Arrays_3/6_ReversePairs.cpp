#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class Solution {
private:
  void merge(std::vector<int> &nums, int start, int mid, int end) {
    std::vector<int> temp;
    int left = start, right = mid + 1;

    while (left <= mid && right <= end) {
      if (nums[left] <= nums[right]) {
        temp.push_back(nums[left]);
        left++;
      } else {
        temp.push_back(nums[right]);
        right++;
      }
    }

    while (left <= mid) {
      temp.push_back(nums[left]);
      left++;
    }
    while (right <= end) {
      temp.push_back(nums[right]);
      right++;
    }

    for (int i = start; i <= end; i++) {
      nums[i] = temp[i - start];
    }
  }

  int mergeSort(std::vector<int> &nums, int l, int r) {
    int cnt = 0;
    if (l < r) {
      int m = (l + r) / 2;
      cnt += mergeSort(nums, l, m);
      cnt += mergeSort(nums, m + 1, r);
      cnt += countPairs(nums, l, m, r);
      merge(nums, l, m, r);
    }
    return cnt;
  }

  int countPairs(std::vector<int> &arr, int start, int mid, int end) {
    int right = mid + 1;
    int cnt = 0;
    for (int i = start; i <= mid; i++) {
      while (right <= end &&
             arr[i] > (2 * static_cast<long long int>(arr[right])))
        right++;
      cnt += (right - (mid + 1));
    }
    return cnt;
  }

public:
  int reversePairs(std::vector<int> &nums) {
    return mergeSort(nums, 0, nums.size() - 1);
  }
};

void FillVectorFromFile(std::vector<int> &vec, const std::string &fileName) {
  std::ifstream mFile;
  mFile.open(fileName);
  if (mFile.is_open()) {
    std::string mString;
    while (std::getline(mFile, mString)) {
      std::istringstream sline(mString);
      int n;
      char c;
      while (sline >> n >> c && c == ',') {
        vec.push_back(n);
      }
      mFile.close();
    }
  }
}

void FillFileFromVector(std::vector<int> &vec, const std::string &fileName) {
  std::ofstream mFile;
  mFile.open(fileName);
  if (mFile.is_open()) {
    for (const int &num : vec) {
      mFile << num << ',';
    }
    mFile.close();
  }
}

int main() {
  Solution s;
  std::vector<int> nums = {5, 4, 3, 2, 1};
  // FillVectorFromFile(nums, "TestCaseFile.txt");
  std::cout << s.reversePairs(nums) << '\n';
  // FillFileFromVector(nums, "Output.txt");

  return 0;
}

/*
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

2147483647,2147483647,2147483647,2147483647,2147483647,2147483647
*/