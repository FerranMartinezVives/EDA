#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;

int n;
VB usat;

void escriu() {
  bool first = true;
  for (int i = 0; i < n; ++i) {
    if (first) {
      cout << usat[i];
      first = false;
    }
    else cout << " " << usat[i];
  }
  cout << endl;
}

void func(int i) {
  if (i == n) return escriu();
  usat[i] = false;
  func(i + 1);
  usat[i] = true;
  func(i + 1);
}

int main() {
  cin >> n;
  usat = VB(n);
  func(0);
}
