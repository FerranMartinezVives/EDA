#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
using VVI = vector<VI>;
using VVB = vector<VB>;
using VPQ = vector<priority_queue<int>>;
using P = pair<int, int>;

VPQ graf;
VB vists;
VI ant;
int n, m;

void escriure() {
  int x = n - 1;
  VI write;
  while (x != 0) {
    write.push_back(x);
    x = ant[x];
  }
  cout << 0;
  for (int i = write.size() - 1; i >= 0; --i) cout << ' ' << write[i];
  cout << endl;
}

void bfs(int ini) {
  queue<int> Q;
  Q.push(ini);
  while (not Q.empty()) {
    int x = Q.front();
    Q.pop();
    while (not graf[x].empty()) {
      int y = -graf[x].top();
      graf[x].pop();
      if (not vists[y]) {
        vists[y] = true;
        ant[y] = x;
        if (y == n - 1) return escriure();
        else Q.push(y);
      }
    }
  }
}

int main() {
  while (cin >> n >> m) {
    graf = VPQ(n);
    vists = VB(n);
    ant = VI(n);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      graf[x].push(-y);
    }
    bfs(0);
  }
}
