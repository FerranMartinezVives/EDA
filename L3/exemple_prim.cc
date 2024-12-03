#include<iostream>
#include<queue>
#include<vector>
using namespace std;

using P = pair<int, int>;
using VP = vector<P>;
using VB = vector<bool>;
using T = pair<int, P>;

int main() {
  int n, m;
  cin >> n >> m;    //n: nombre de vèrtexs, m: nombre d'arestes
  vector<VP> G(n);
  for (int i = 0; i < m; ++i) {
    int x, y, c;
    cin >> x >> y >> c;     //llegim les arestes: vèrtex x, vèrtex y i el cost c
    G[x].push_back(P(c, y));
    G[y].push_back(P(c, x));
  }
  int suma = 0;
  int q = 0;
  VB usat(n, false);
  priority_queue<T, vector<T>, greater<T>> Q;
  Q.push(T(0, P(-1, 0)));
  while (q < n) {
    T a = Q.top();
    Q.pop();
    int c = a.first;
    int x = a.second.first;
    int y = a.second.second;
    if (not usat[y]) {
      usat[y] = true;
      suma += c;
      ++q;
      if (x != -1) cout << x << ' ' << y << ' ' << c << endl;
      for (P b : G[y]) Q.push(T(b.first, P(y, b.second)));
    }
  }
  cout << suma << endl;
}
