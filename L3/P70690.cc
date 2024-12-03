#include<iostream>
#include<vector>
using namespace std;

using VC = vector<char>;
using VVC = vector<VC>;

int n, m;
VVC M;

bool dfs(int x, int y) {
  if (x < 0 or x >= n or y < 0 or y >= m or M[x][y] == 'X') return false;
  if (M[x][y] == 't') return true;
  M[x][y] = 'X';
  return dfs(x + 1, y) or dfs(x - 1, y) or dfs(x, y + 1) or dfs(x, y - 1);
}

int main() {
  cin >> n >> m;
  M = VVC(n, VC(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> M[i][j];
  }
  int r, c;
  cin >> r >> c;
  if (dfs(r - 1, c - 1)) cout << "yes" << endl;
  else cout << "no" << endl;
}
