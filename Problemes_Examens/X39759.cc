#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using P = pair<int, int>;
using VP = vector<P>;

VI inc_x = {-2, -1, 1, 2, 2, 1, -1, -2};
VI inc_y = {-1, -2, -2, -1, 1, 2, 2, 1};

int n, m, W, L, k;
VI puntuacio;
int max_punts;
VVI tauler;

bool bfs(int x_ini, int y_ini, int x_fi, int y_fi) {
  tauler = VVI(n, VI(m, -1));
  queue<P> Q;
  tauler[x_ini][y_ini] = 0;
  Q.push(P(x_ini, y_ini));
  while (not Q.empty()) {
    P p = Q.front();
    Q.pop();
    int i = p.first;
    int j = p.second;
    for (int d = 0; d < 8; ++d) {
      int i2 = i + inc_x[d];
      int j2 = j + inc_y[d];
      if (i2 >= 0 and i2 < n and j2 >= 0 and j2 < m and tauler[i2][j2] == -1) {
        tauler[i2][j2] = tauler[i][j] + 1;
        if (i2 == x_fi and j2 == y_fi) {
          puntuacio.push_back(W - tauler[i2][j2] * L);
          max_punts += W - tauler[i2][j2] * L;
          return true;
        }
        else Q.push(P(i2, j2));
      }
    }
  }
  puntuacio.push_back(0);
  return false;
}

int main() {  //NO FUNCIONA LO DELS PUNTS
  while (cin >> n >> m) {
    max_punts = 0;
    cin >> W >> L >> k;
    int x_ini, y_ini;
    x_ini = y_ini = 0;
    VP finals(k);
    puntuacio = VI(0);
    for (int i = 0; i < k; ++i) cin >> finals[i].first >> finals[i].second;
    int i = 0;
    bool end = false;
    while (not end and i < k) {
      end = bfs(x_ini, y_ini, finals[i].first, finals[i].second);
      if (not end) {
        x_ini = finals[i].first;
        y_ini = finals[i].second;
        ++i;
      }
    }
    int resta = 0;
    for (int j = i; j >= 0; --j) {
      resta += puntuacio[j];
      if (max_punts - resta > max_punts) max_punts -= resta;
    }
    cout << max_punts << endl;
  }
}
