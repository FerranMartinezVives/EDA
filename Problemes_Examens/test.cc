#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using VI = vector<int>;
using VC = vector<char>;
using VVC = vector<VC>;
using VB = vector<bool>;
using VVB = vector<VB>;
using P = pair<int, int>;

VI inc_x = {1, -1, 0, 0};
VI inc_y = {0, 0, 1, -1};

int n, m;
VVC tauler;

bool monster_free(int x, int y) {
  for (int d = 0; d < 4; ++d) {
    int i = x + inc_x[d];
    int j = y + inc_y[d];
    if (tauler[i][j] == 'M') return false;
  }
  return true;
}

void bfs(int x, int y) {
  VVB vists(n, VB(m, false));
  vists[x][y] = true;
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
      if (i2 >= 0 and i2 < n and j2 >= 0 and j2 < m and monster_free(i2, j2)) {
        vists[i2][j2] = true;
        if (tauler[i2][j2] == 'F') {
          cout << "SI" << endl;
          return;
        }
        Q.push(P(i2, j2));
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  while (cin >> n >> m) {
    tauler = VVC(n, VC(m));
    int x, y;
    x = y = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> tauler[i][j];
        if (tauler[i][j] == 'I') {
          x = i;
          y = j;
        }
      }
    }
    bfs(x, y);
  }
}
