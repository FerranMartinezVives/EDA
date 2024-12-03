#include<iostream>
#include<vector>
using namespace std;

int i_resistant_search(int i, int j, double x, const vector<double>& v) {
  if (i > j) return -1;
  int m = (i + j) / 2;
  double y = v[m];
  if (m > 0 and v[m - 1] > y) y = v[m - 1];
  if (m < (int)v.size() - 1 and v[m + 1] < y) y = v[m + 1];
  if (x < y) return i_resistant_search(i, m - 1, x, v);
  if (x > y) return i_resistant_search(m + 1, j, x, v);
  return m;
}

bool resistant_search(double x, const vector<double>& v) {
  int n = i_resistant_search(0, v.size() - 1, x, v);
  return n != -1;
}

int main() {
  int n, x;
  while (cin >> x >> n) {
    vector<double> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    if (resistant_search(x, v)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}
