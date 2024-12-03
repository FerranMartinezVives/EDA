#include<iostream>
#include<map>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    map<string, int> colleccio;
    int suma_jocs = 0;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      ++suma_jocs;
      auto it = colleccio.find(s);
      if (it == colleccio.end()) colleccio.insert(make_pair(s, 1));
      else ++(it->second);
    }
    int j;
    cin >> j;
    for (int i = 0; i < j; ++i) {
      string s;
      cin >> s;
      auto it = colleccio.find(s);
      if (it == colleccio.end()) {
        colleccio.insert(make_pair(s, 1));
        ++suma_jocs;
      }
      else if (it->second < suma_jocs - it->second) {
        ++(it->second);
        ++suma_jocs;
      }
    }
    for (auto it = colleccio.begin(); it != colleccio.end(); ++it) cout << it->first << " " << it->second << endl;
    cout << "--------------------" << endl;
  }
}
