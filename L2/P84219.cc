#include<iostream>
#include<vector>
using namespace std;

int i_first_occurrence(int i, int j, double x, const vector<double>& v) {
  if (i > j) return -1;
  int n = (i + j) / 2;
  if (x < v[n]) return i_first_occurrence(i, n - 1, x, v);
  if (x > v[n]) return i_first_occurrence(n + 1, j, x, v);
  int m = i_first_occurrence(i, n - 1, x, v);
  if (m != -1) return m;
  return n;
}

int first_occurrence(double x, const vector<double>& v) {
  return i_first_occurrence(0, v.size() - 1, x, v);
}

int main() {
  double x;
  int n;
  cin >> x >> n;

  vector<double> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int oc = first_occurrence(x, v);
  cout << oc << endl;
}
