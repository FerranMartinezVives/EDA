#include<iostream>
#include<vector>
using namespace std;

using VS = vector<string>;

VS seq;
int n;

int search(string& w, int esq, int dre) {
  if (dre < esq) return n;
  int m = (dre - esq) / 2;
  if (w > seq[m]) return search(w, m + 1, dre);
  else {
    if (m == 0 or w > seq[m - 1]) return m;
    else return search(w, esq, m - 1);
  }
}

void insert(string& w) {
  int m = search(w, 0, n - 1);
  cout << m << endl;
  string aux = w;
  for (int i = m; i < n; ++i) {
    string aux2;
    aux2 = seq[i];
    seq[i] = aux;
    aux = aux2;
  }
  seq.push_back(aux);
}

int main() {
  n = 0;
  string w;
  while (cin >> w and w != "END") {
    insert(w);
    ++n;
    int med = (n + 1) / 2;
    cout << seq[med - 1] << endl;
  }
}
