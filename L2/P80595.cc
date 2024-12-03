#include<iostream>
#include<vector>
using namespace std;

int i_n_inv(int e, int d, vector<int>& v) {
  int n = d - e + 1;
  if (n <= 1) return 0;
  int m = (e + d) / 2;
  int res = i_n_inv(e, m, v) + i_n_inv(m + 1, d, v);
  vector<int> buffer(n);
  int i = e;
  int j = m + 1;
  int k = 0;
  while (i <= m and j < v.size()) {
    if (v[i] <= v[j]) {
      buffer[k] = v[i];
      ++i;
    }
    else {
      buffer[k] = v[j];
      ++j;
      res += m - i + 1;
    }
    ++k;
  }
  while (i <= m) {
    buffer[k] = v[i];
    ++k;
    ++i;
  }
  while (j < v.size()) {
    buffer[k] = v[j];
    ++k;
    ++j;
  }
  for (int l = 0; l < m; ++l) v[e + l] = buffer[l];
  return res;
}

int n_inv(vector<int>& v) {
  return i_n_inv(0, v.size() - 1, v);
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << n_inv(v) << endl;
  }
}

//NO SURT CORRECTAMENT!!!
