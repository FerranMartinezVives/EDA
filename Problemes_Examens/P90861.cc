#include<iostream>
#include<vector>
#include<queue>
using namespace std;

using Q = queue<string>;
using VQ = vector<Q>;

int main() {
  int n;
  cin >> n;
  VQ cues(n);
  for (int i = 0; i < n; ++i) {
    string nom;
    while (cin >> nom) cues[i].push(nom); //COM CONY M'HO FAIG PER SABER QUE HA ACABAT LA LÍNIA?????
  }
  cout << "SORTIDES" << endl << "--------" << endl;
  string s;
  while (cin >> s) {
    if (s == "ENTRA") {
      string nom;
      int x;
      cin >> nom >> x;
      if (x >= 1 and x <= n) cues[x - 1].push(nom);
    }
    else if (s == "SURT") {
      int x;
      cin >> x;
      if (x >= 1 and x <= n and not cues[x - 1].empty()) {
        cout << cues[x - 1].front() << endl;
        cues[x - 1].pop();
      }
    }
  }
  cout << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
  for (int i = 0; i < n; ++i) {
    cout << "cua " << i + 1 << ":";
    while (not cues[i].empty()) {
      cout << " " << cues[i].front();
      cues[i].pop();
    }
    cout << endl;
  }
}
