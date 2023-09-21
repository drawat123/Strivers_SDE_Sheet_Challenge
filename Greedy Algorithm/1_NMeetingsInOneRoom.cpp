// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

#include <algorithm>
#include <vector>

class Solution {
public:
  int maxMeetings(int start[], int end[], int n) {
    int cnt = 1, prevMaxEnd = -1;
    std::vector<std::pair<int, int>> mVec;
    for (int i = 0; i < n; i++) {
      mVec.push_back({start[i], end[i]});
    }

    std::sort(mVec.begin(), mVec.end(),
              [](const std::pair<int, int> &v1, const std::pair<int, int> &v2) {
                return v1.second < v2.second;
              });

    for (const auto &p : mVec) {
      if (p.first > prevMaxEnd) {
        cnt++;
        prevMaxEnd = p.second;
      }
    }

    return cnt;
  }
};