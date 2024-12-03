#include<iostream>
#include<vector>
using namespace std;

using VI = vector<int>;
using VB = vector<bool>;

int s, n;
VI nums;
VB usat;

void escriu() {
  bool primer = true;
  for (int i = 0; i < n; ++i) {
    if (usat[i]) {
      cout << (primer ? '{' : ',');
      primer = false;
      cout << nums[i];
    }
  }
  if (primer) cout << '{';
  cout << '}' << endl;
}

void f(int i, int suma) {
  if (i == n) {
    if (suma == s) escriu();
    return;
  }
  usat[i] = false;
  f(i + 1, suma);
  usat[i] = true;
  f(i + 1, suma + nums[i]);
}

int main() {
  cin >> s >> n;
  nums = VI(n);
  usat = VB(n, false);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  f(0, 0);
}
