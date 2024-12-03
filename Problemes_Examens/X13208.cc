#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using P = pair<int, int>; //(x, y)
using T = pair<int, P>;   //(cost, (x, y))

VI inc_x = {1, -1, 0, 0};
VI inc_y = {0, 0, 1, -1};

int n;
VVI tauler;

void dijkstra() {
  VVB vists(n, VB(n, false));
  priority_queue<T> PQ;
  PQ.push(T(-tauler[n / 2][n / 2], P(n / 2, n / 2)));
  vists[n / 2][n / 2] = true;
  while (not PQ.empty()) {
    T t = PQ.top();
    PQ.pop();
    int cost = -t.first;
    int i = t.second.first;
    int j = t.second.second;
    if (i == 0 or i == n - 1 or j == 0 or j == n - 1) {
      cout << cost << endl;
      return;
    }
    for (int d = 0; d < 4; ++d) {
      int i2 = i + inc_x[d];
      int j2 = j + inc_y [d];
      if (i2 >= 0 and i2 < n and j2 >= 0 and j2 < n and not vists[i2][j2]) {
        vists[i2][j2] = true;
        PQ.push(T(-cost - tauler[i2][j2], P(i2, j2)));
      }
    }
  }
}

int main() {
  while (cin >> n) {
    tauler = VVI(n, VI(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) cin >> tauler[i][j];
    }
    dijkstra();
  }
}
