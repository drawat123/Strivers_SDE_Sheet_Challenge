// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

class Solution {
private:
  bool isValid(int node, int n, int color, bool graph[101][101],
               int colorArr[]) {
    for (int i = 0; i < n; i++) {
      if (i != node && graph[node][i] && colorArr[i] == color) {
        return false;
      }
    }

    return true;
  }
  bool helper(int node, int m, int n, bool graph[101][101], int colorArr[]) {
    if (node == n) {
      return true;
    }

    for (int color = 1; color <= m; color++) {
      if (isValid(node, n, color, graph, colorArr)) {
        colorArr[node] = color;
        if (helper(node + 1, m, n, graph, colorArr)) {
          return true;
        }
        colorArr[node] = 0;
      }
    }

    return false;
  }

public:
  bool graphColoring(bool graph[101][101], int m, int n) {
    int colorArr[n] = {0};
    return helper(0, m, n, graph, colorArr);
  }
};