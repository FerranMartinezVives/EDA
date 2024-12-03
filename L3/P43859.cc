#include<iostream>
#include<queue>
#include<vector>
using namespace std;

using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;
using VI = vector<int>;

const int INF = 1e9;

VVP G;
int n;
int ini, fi;

void dijkstra() {
  VI dist(n, INF);
  priority_queue<P> Q;
  dist[ini] = 0;
  Q.push(P(0, ini));
  while (not Q.empty()) {
    P a = Q.top();
    Q.pop();
    int dx = -a.first;
    int x = a.second;
    if (dx == dist[x]) {
      if (x == fi) {
        cout << dx << endl;
        return;
      }
      for (P arc : G[x]) {
        int dy = dx + arc.first;
        int y = arc.second;
        if (dy < dist[y]) {
          dist[y] = dy;
          Q.push(P(-dy, y));
        }
      }
    }
  }
  cout << "no path from " << ini << " to " << fi << endl;
}

int main() {
  int m;
  while (cin >> n >> m) {
    G = VVP(n);
    for (int i = 0; i < m; ++i) {
      int x, y, c;
      cin >> x >> y >> c;
      G[x].push_back(P(c, y));
    }
    cin >> ini >> fi;
    dijkstra();
  }
}
