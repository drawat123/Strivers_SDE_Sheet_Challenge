#include <string>
#include <vector>

class Solution {
private:
  bool isValid(int row, int col, std::vector<std::vector<bool>> &vis,
               std::vector<std::vector<int>> &m) {
    if (row < 0 || row >= m.size() || col < 0 || col >= m.size()) {
      return false;
    }

    return !vis[row][col] && m[row][col];
  }

  void helper(int row, int col, std::string &str,
              std::vector<std::vector<bool>> &vis,
              std::vector<std::vector<int>> &m, std::vector<std::string> &res) {
    if (row == m.size() - 1 && col == m.size() - 1) {
      res.push_back(str);
      return;
    }

    std::vector<std::pair<int, int>> vec{
        {-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // row and col
    std::vector<char> dir{'U', 'R', 'D', 'L'};

    vis[row][col] = true;
    for (int i = 0; i < 4; i++) {
      int newRow = row + vec[i].first, newCol = col + vec[i].second;
      if (isValid(newRow, newCol, vis, m)) {
        str.push_back(dir[i]);
        helper(newRow, newCol, str, vis, m, res);
        str.pop_back();
      }
    }
    vis[row][col] = false;
  }

public:
  std::vector<std::string> findPath(std::vector<std::vector<int>> &m, int n) {
    std::vector<std::string> res;
    if (!m[0][0])
      return res;

    std::vector<std::vector<bool>> vis(m.size(),
                                       std::vector<bool>(m.size(), false));
    std::string str;
    helper(0, 0, str, vis, m, res);

    return res;
  }
};

int main() {
  Solution s;
  std::vector<std::vector<int>> m = {
      {0, 1, 1, 1}, {1, 1, 1, 0}, {1, 0, 1, 1}, {0, 0, 1, 1}};
  int n = 4;
  s.findPath(m, n);

  return 0;
}