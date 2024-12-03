#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VC = vector<char>;

int n, c;
VI perm, usat;
VC lletres = {'x', 'y', 'z'};

void escriu() {
  for (int i = 0; i < n; ++i) cout << lletres[perm[i]];
  cout << endl;
}

void f(int i) {
  if (i == n) return escriu();
  for (int x = 0; x < 3; ++x) {
    VI usat_aux = usat;
    if (usat[x] < c) {
      for (int y = 0; y < 3; ++y) {
        if (y != x) usat[y] = 0;
      }
      ++usat[x];
      perm[i] = x;
      f(i + 1);
      usat = usat_aux;
    }
  }
}

int main() {
  while (cin >> n >> c) {
    perm = VI(n);
    usat = VI(3, 0);
    f(0);
    for (int i = 0; i < 20; ++i) cout << '-';
    cout << endl;
  }
}
