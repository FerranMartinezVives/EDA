#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using P = pair<int, int>;
using VC = vector<char>;
using VI = vector<int>;
using VVC = vector<VC>;
using VVI = vector<VI>;

const VI incx = {1, -1, 0, 0};
const VI incy = {0, 0, 1, -1};

VVC M;

int main() {
  int n, m;
  while (cin >> n >> m) {
    M = VVC(n, VC(m));
    int it = -1;
    int jt = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> M[i][j];
        if (M[i][j] == 'T') {
          it = i;
          jt = j;
        }
      }
    }
    if (it == -1) cout << "El telecos ha fugit." << endl;
    else {
      VVI dist(n, VI(m, -1));
      VVI pers(n, VI(m));
      queue<P> Q;
      dist[0][0] = 0;
      pers[0][0] = (M[0][0] == 'P');
      Q.push(P(0, 0));
      while (not Q.empty()) {
        P p = Q.front();
        Q.pop();
        int i = p.first;
        int j = p.second;
        for (int d = 0; d < 4; ++d) {
          int i2 = i + incx[d];
          int j2 = j + incy[d];
          if (i2 >= 0 and j2 >= 0 and i2 < n and j2 < m and M[i2][j2] != '#') {
            bool b = (M[i2][j2] == 'P');
            if (dist[i2][j2] == -1) {
              dist[i2][j2] = dist[i][j] + 1;
              pers[i2][j2] = pers[i][j] + b;
              Q.push(P(i2, j2));
            }
            else if (dist[i2][j2] == dist[i][j] + 1) {
              pers[i2][j2] = max(pers[i2][j2], pers[i][j] + b);
            }
          }
        }
      }
      if (dist[it][jt] == -1) cout << "El telecos esta amagat." << endl;
      else cout << dist[it][jt] << " " << pers[it][jt] << endl;
    }
  }
}
