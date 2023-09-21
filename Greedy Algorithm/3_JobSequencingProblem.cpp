// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

#include <algorithm>
#include <vector>

struct Job {
  int id;     // Job Id
  int dead;   // Deadline of job
  int profit; // Profit if job is over before or on deadline
};

class Solution {
public:
  std::vector<int> JobScheduling(Job arr[], int n) {
    int profit = 0, maxJobs = 0;
    std::sort(arr, arr + n, [](const Job &j1, const Job &j2) {
      return j1.profit > j2.profit;
    });

    Job *mJob =
        std::max_element(arr, arr + n, [](const Job &j1, const Job &j2) {
          return j1.dead < j2.dead;
        });
    std::vector<int> pVec(mJob->dead + 1, -1);

    for (int i = 0; i < n; i++) {
      for (int j = arr[i].dead; j > 0; j--) {
        if (pVec[j] == -1) {
          pVec[j] = i;
          profit += arr[i].profit;
          maxJobs++;
          break;
        }
      }
    }

    return {maxJobs, profit};
  }
};