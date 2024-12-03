#include<iostream>
#include<vector>
#include<stack>
using namespace std;

using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;

int n, m;
VVI G;
VI vists;

bool it_dfs(int x0) {
  stack<int> S;
  S.push(x0);
  while (not S.empty()) {
    int x = S.top();
    S.pop();
    for (int y : G[x]) {
      if(vists[y] == vists[x]) return false;
      else if (vists[y] == 0) {
        if (vists[x] == 1) vists[y] = 2;
        else vists[y] = 1;
        S.push(y);
      }
    }
  }
  return true;
}

int main() {
  while (cin >> n >> m) {
    G = VVI(n);
    vists = VI(n, 0);
    int x0 = -1;
    bool first = true;
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      if (first) {
        first = false;
        x0 = x;
        vists[x0] = 1;
      }
      G[x].push_back(y);
      G[y].push_back(x);
    }
    if (x0 == -1 or it_dfs(x0)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
