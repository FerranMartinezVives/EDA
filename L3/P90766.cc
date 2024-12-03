#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VC = vector<char>;
using VVC = vector<VC>;

int n, m;
VVC mapa;

int dfs(int x, int y) {
  if (x < 0 or y < 0 or x >= n or y >= m or mapa[x][y] == 'X') return 0;
  int tresor = 0;
  if (mapa[x][y] == 't') ++tresor;
  mapa[x][y] = 'X';
  return tresor += dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
}

int main() {
  cin >> n >> m;
  mapa = VVC(n, VC(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> mapa[i][j];
  }
  int f, c;
  cin >> f >> c;
  cout << dfs(f - 1, c - 1) << endl;
}
