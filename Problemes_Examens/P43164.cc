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

void bfs(int x, int y) {
  VVI dist(n, VI(m, -1));
  dist[x][y] = 0;
  int max_dist = -1;
  int seg_max_dist = -1;
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
      if (i2 >= 0 and i2 < n and j2 >= 0 and j2 < m and dist[i2][j2] == -1) {
        dist[i2][j2] = dist[i][j] + 1;
        if (tauler[i2][j2] == 't') {
          if (dist[i2][j2] >= max_dist) {
            seg_max_dist = max_dist;
            max_dist = dist[i2][j2];
          }
          else if (dist[i2][j2] > seg_max_dist) seg_max_dist = dist[i2][j2];
        }
        if (tauler[i2][j2] != 'X') Q.push(P(i2, j2));
      }
    }
  }
  if (seg_max_dist == -1) cout << "no es pot arribar a dos o mes tresors" << endl;
  else cout << "segona distancia maxima: " << seg_max_dist << endl;
}

int main() {
  cin >> n >> m;
  tauler = VVC(n, VC(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> tauler[i][j];
  }
  int x, y;
  cin >> x >> y;
  bfs(x - 1, y - 1);
}
