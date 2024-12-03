#include<iostream>
#include<vector>
using namespace std;

using VB = vector<bool>;

VB col, diags1, diags2;
int n, sum;

void func(int i) {
  if (i == n) {
    ++sum;
    return;
  }
  for (int j = 0; j < n; ++j) {
    if (not col[j] and not diags1[i + j] and not diags2[i + n - 1 - j]) {
      col[j] = diags1[i + j] = diags2[i + n - 1 - j] = true;
      func(i + 1);
      col[j] = diags1[i + j] = diags2[i + n - 1 - j] = false;
    }
  }
}

int main() {
  cin >> n;
  col = VB(n, false);
  diags1 = diags2 = VB(2 * n - 1, false);
  sum = 0;
  func(0);
  cout << sum << endl;
}
