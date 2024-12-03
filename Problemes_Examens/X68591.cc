#include<iostream>
#include<vector>
using namespace std;

using VB = vector<bool>;
using VI = vector<int>;
using VVI = vector<VI>;

VVI graf;
VB vists;

int mida_cc (int node) {
  if (vists[node]) return 0;
  vists[node] = true;
  int mida = 1;
  for (int i = 0; i < (int)graf[node].size(); ++i) mida = mida + mida_cc(graf[node][i]);
  return mida;
}

int main() {
  int  n, m;
  while (cin >> n >> m) {
    graf = VVI(n);
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      graf[x].push_back(y);
      graf[y].push_back(x);
    }
    vists = VB(n, false);
    int mida_max = 0;
    int mida_min = 1000000;
    for (int i = 0; i < n; ++i) {
      if (not vists[i]) {
        int mida = mida_cc(i);
        mida_max = max(mida, mida_max);
        mida_min = min(mida, mida_min);
      }
    }
    cout << mida_min << " " << mida_max << endl;
  }
}
