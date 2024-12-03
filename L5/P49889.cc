#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VC = vector<char>;
using VVC = vector<VC>;

int n;
VVI perm;
VVB usat;
VVC lletra;

void escriure() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) cout << lletra[j][perm[j][i]];
  }
  cout << endl;
}

void f(int i) {
  if (i == 2 * n) return escriure();
  int j = i % 2;
  for (int x = 0; x < n; ++x) {
    if (not usat[j][x]) {
      usat[j][x] = true;
      perm[j][i / 2] = x;
      f(i + 1);
      usat[j][x] = false;
    }
  }
}

int main() {
  cin >> n;
  lletra = VVC(2, VC(n));
  usat = VVB(2, VB(n, false));
  perm = VVI(2, VI(n, false));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) cin >> lletra[i][j];
  }
  f(0);
}
