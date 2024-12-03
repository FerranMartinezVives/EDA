#include<iostream>
#include<queue>
#include<vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;

int main() {
  int n, m;
  while (cin >> n >> m) {
    VVI G(n);
    VI grau(n, 0);
    while (m > 0) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      ++grau[y];
      --m;
    }
    priority_queue<int> q;
    for (int x = 0; x < n; ++x) {
      if (grau[x] == 0) q.push(-x);
    }
    bool first = true;
    while (not q.empty()) {
      int x = -q.top();
      q.pop();
      if (first) {
        cout << x;
        first = false;
      }
      else cout << ' ' << x;
      for (int i = 0; i < (int)G[x].size(); ++i) {
        int y = G[x][i];
        --grau[y];
        if (grau[y] == 0) q.push(-y);
      }
    }
    cout << endl;
  }
}
