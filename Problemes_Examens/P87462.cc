#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;
using P = pair<int, int>;

VI inc_x = {1, -1, 0, 0};
VI inc_y = {0, 0, 1, -1};

VVC tauler;
int n, m;

bool ghost_free(int x, int y) {
  VI inc_i = {0, 1, 1, 1, 0, -1, -1, -1};
  VI inc_j = {-1, -1, 0, 1, 1, 1, 0, -1};
  for (int d = 0; d < 8; ++d) {
    int i = x + inc_i[d];
    int j = y + inc_j[d];
    if (tauler[i][j] == 'F') return false;
  }
  return true;
}

bool bfs(int x, int y) {
  if (not ghost_free(x, y)) return false;
  VVI dist(n, VI(m, -1));
  dist[x][y] = 0;
  queue<P> Q;
  Q.push(P(x, y));
  while (not Q.empty()) {
    P p = Q.front();
    Q.pop();
    int i = p.first;
    int j = p.second;
    for (int d = 0; d < 4; ++d) {
      int i2 = i + inc_x[d];
      int j2 = j + inc_y[d];
      if (dist[i2][j2] == -1 and tauler[i2][j2] != 'X' and ghost_free(i2, j2)) {
        if (tauler[i2][j2] == 'B') return true;
        Q.push(P(i2, j2));
      }
      if (dist[i2][j2] == -1) dist[i2][j2] = dist[i][j] + 1;
    }
  }
  return false;
}

int main() {
  while (cin >> n >> m) {
    tauler = VVC(n, VC(m));
    int x, y;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> tauler[i][j];
        if (tauler[i][j] == 'P') {
          x = i;
          y = j;
        }
      }
    }
    if (bfs(x, y)) cout << "si" << endl;
    else cout << "no" << endl;
  }
}
