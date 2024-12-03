#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;

int n;
VI perm;
VB usat;

void escriure() {
  for (int i = 0; i < n; ++i) {
    char c = 'a' + perm[i];
    cout << c;
  }
  cout << endl;
}

void func(int i) {
  if (i == n) return escriure();
  for (int x = 0; x < n; ++x) {
    if (not usat[x] and (i == 0 or perm[i - 1] != x - 1)) {
      usat[x] = true;
      perm[i] = x;
      func(i + 1);
      usat[x] = false;
    }
  }
}

int main() {
  cin >> n;
  perm = VI(n);
  usat = VB(n, false);
  func(0);
}
