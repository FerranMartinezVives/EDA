#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;
using VS = vector<string>;

int n;
VI perm;
VB usat;
VS pars;

void escriu() {
  cout << "(";
  bool first = true;
  for (int i = 0; i < n; ++i) {
    if (first) {
      first = false;
      cout << pars[perm[i]];
    }
    else cout << "," << pars[perm[i]];
  }
  cout << ")" << endl;
}

void f(int i) {
  if (i == n) return escriu();
  for (int x = 0; x < n; ++x) {
    if (not usat[x]) {
      usat[x] = true;
      perm[i] = x;
      f(i + 1);
      usat[x] = false;
    }
  }
}

int main() {
  cin >> n;
  perm = VI(n);
  usat = VB(n, false);
  pars = VS(n);
  for (int i = 0; i < n; ++i) cin >> pars[i];
  f(0);
}
