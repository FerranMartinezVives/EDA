#include<iostream>
#include<stack>
#include<vector>
using namespace std;

using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;

VVI G;
int n, nv;
VB vists;

bool cc_es_arbre(int ini) {
  vists[ini] = true;
  ++nv;
  stack<P> S;
  for (int i : G[ini]) S.push(P(ini, i));
  while (not S.empty()) {
    P a = S.top();
    S.pop();
    int x = a.first;
    int y = a.second;
    if (vists[y]) return false;
    else {
      vists[y] = true;
      ++nv;
      for (int i : G[y]) {
        if (i != x) S.push(P(y, i));
      }
    }
  }
  return true;
}

void dfs() {
  vists = VB(n, false);
  nv = 0;
  int i = 0;
  int arbres = 0;
  while (arbres != -1 and nv < n) {
    if (not vists[i]) {
      if (cc_es_arbre(i)) ++arbres;
      else arbres = -1;
    }
    ++i;
  }
  if (arbres == -1) cout << "no" << endl;
  else cout << arbres << endl;
}

int main() {
  int m;
  while (cin >> n >> m) {
    G = VVI(n);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    dfs();
  }
}
