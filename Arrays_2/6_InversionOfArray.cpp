#include <vector>

int countInversions(long long *arr, int start, int mid, int end) {
  int right = mid + 1;
  int cnt = 0;
  for (int i = start; i <= mid; i++) {
    while (right <= end && arr[i] > arr[right])
      right++;
    cnt += (right - (mid + 1));
  }
  return cnt;
}

void merge(long long *nums, int start, int mid, int end) {
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

int mergeSort(long long *nums, int l, int r) {
  int cnt = 0;
  if (l < r) {
    int m = (l + r) / 2;
    cnt += mergeSort(nums, l, m);
    cnt += mergeSort(nums, m + 1, r);
    cnt += countInversions(nums, l, m, r);
    merge(nums, l, m, r);
  }
  return cnt;
}

long long getInversions(long long *arr, int n) {
  return mergeSort(arr, 0, n - 1);
}