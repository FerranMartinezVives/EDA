#include<iostream>
#include<queue>
#include<vector>
using namespace std;

using P = pair<int, int>; //vèrtexs x i y
using T = pair<int, P>;   //cost, vèrtexs x i y
using VB = vector<bool>;
using VP = vector<P>;
using VVP = vector<VP>;

int main() {
  int n, m;
  while (cin >> n >> m) {
    VVP G(n);
    for (int i = 0; i < m; ++i) {
      int x, y, c;
      cin >> x >> y >> c;
      G[x - 1].push_back(P(c, y - 1));
      G[y - 1].push_back(P(c, x - 1));
    }
    VB seen(n, false);
    priority_queue<T, vector<T>, greater<T>> Q;
    Q.push(T(0, P(-1, 0)));
    int weight = 0;
    int q = 0;
    while (q < n) {
      T a = Q.top();
      Q.pop();
      int c = a.first;
      int y = a.second.second;
      if (not seen[y]) {
        seen[y] = true;
        ++q;
        weight += c;
        for (int j = 0; j < (int)G[y].size(); ++j) Q.push(T(G[y][j].first, P(y, G[y][j].second)));
      }
    }
    cout << weight << endl;
  }
}
