#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VC = vector<char>;
using VB = vector<bool>;

VC adn = {'A', 'C', 'G', 'T'};
VI perm;
int n;

void escriu() {
  for (int i = 0; i < n; ++i) cout << adn[perm[i]];
  cout << endl;
}

void func(int i) {
  if (i == n) return escriu();
  for (int x = 0; x < 4; ++x) {
    perm[i] = x;
    func(i + 1);
  }
}

int main() {
  cin >> n;
  perm = VI(n);
  func(0);
}
