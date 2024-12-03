#include<iostream>
#include<vector>
#include<map>
using namespace std;

using VC = vector<char>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VI = vector<int>;
using VS = vector<string>;

VC especs;
VVB incomps;
VB usat;
VI perm;
int n, m;

void escriure() {
  for (int i = 0; i < n; ++i) cout << especs[perm[i]];
  cout << endl;
}

bool ok(int i, int x) {
  return i == 0 or not incomps[perm[i - 1]][x];
}

void func(int i) {
  if (i == n) return escriure();
  for (int x = 0; x < n; ++x) {
    if (not usat[x] and ok(i, x)) {
      usat[x] = true;
      perm[i] = x;
      func(i + 1);
      usat[x] = false;
    }
  }
}

int main() {
  cin >> n;
  especs = VC(n);
  map<char, int> map;
  for (int i = 0; i < n; ++i) {
    cin >> especs[i];
    map.insert(pair<char, int>(especs[i], i));
  }
  cin >> m;
  incomps = VVB(n, VB(n, false));
  for (int x = 0; x < m; ++x) {
    char c1, c2;
    cin >> c1 >> c2;
    int i = map.find(c1)->second;
    int j = map.find(c2)->second;
    incomps[i][j] = incomps[j][i] = true;
  }
  perm = VI(n);
  usat = VB(n, false);
  func(0);
}
