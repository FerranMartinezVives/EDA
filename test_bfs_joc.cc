#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VC = vector<char>;
using VVC = vector<VC>;
using VS = vector<string>;

VI inc_x = {-1, 1, 0, 0};
VI inc_y = {0, 0, -1, 1};

VS dirs = {"Up", "Down", "Left", "Right"};
int n;
VVC tauler;

bool pos_ok(int x, int y) {
  return x >= 0 and x < n and y >= 0 and y < n;
}

int bfs(int x, int y) {
  VVI direccions(n, VI(n, -1));
  queue<P> Q;
  Q.push(P(x, y));
  direccions[x][y] = 0;
  while (not Q.empty()) {
    P p = Q.front();
    Q.pop();
    int i = p.first;
    int j = p.second;
    for (int d = 0; d < 4; ++d) {
      int i2 = i + inc_x[d];
      int j2 = j + inc_y[d];
      if (pos_ok(i2, j2) and direccions[i2][j2] == -1) {
        cout << "s'observa la posicio [" << i2 << ", " << j2 << "]" << endl;
        if (direccions[i][j] == 0) direccions[i2][j2] = d + 1;
        else direccions[i2][j2] = direccions[i][j];
        if (tauler[i2][j2] == 'm') return direccions[i2][j2] - 1;
        else if (tauler[i2][j2] != 'W') Q.push(P(i2, j2));
      }
    }
  }
  return -1;
}

int main() {
  cin >> n;
  tauler = VVC(n, VC(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) cin >> tauler[i][j];
  }
  int f, c;
  cin >> f >> c;
  int dir = bfs(f, c);
  if (dir != -1) cout << "menjar mes proper en direccio " << dirs[dir] << endl;
  else cout << "no s'ha trobat menjar" << endl;
}
