#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;

VI inc_x = {1, -1, 0, 0};
VI inc_y = {0, 0, 1, -1};

int n, m;
VVC mapa;

void bfs(int x, int y) {
  queue<P> cua;
  VVI dist(n, VI(m, -1));
  cua.push(P(x, y));
  dist[x][y] = 0;
  int d_max = -1;
  while (not cua.empty()) {
    P p = cua.front();
    cua.pop();
    int i = p.first;
    int j = p.second;
    for (int d = 0; d < 4; ++d) {
      int i2 = i + inc_x[d];
      int j2 = j + inc_y[d];
      if (i2 >= 0 and j2 >= 0 and i2 < n and j2 < m and dist[i2][j2] == -1) {
        dist[i2][j2] = dist[i][j] + 1;
        if (mapa[i2][j2] == 't') d_max = dist[i2][j2];
        if (mapa[i2][j2] != 'X') cua.push(P(i2, j2));
      }
    }
  }
  if (d_max == -1) cout << "no es pot arribar a cap tresor" << endl;
  else cout << "distancia maxima: " << d_max << endl;
}

int main() {
  cin >> n >> m;
  mapa = VVC(n, VC(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> mapa[i][j];
  }
  int f, c;
  cin >> f >> c;
  bfs(f - 1, c - 1);
}
