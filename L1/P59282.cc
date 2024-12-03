#include<iostream>
#include<map>
using namespace std;

int main() {
  cout.setf(ios::fixed);
  cout.precision(4);
  map<int, int> m;
  double sum = 0;
  double size = 0;
  string command;
  while (cin >> command) {
    bool empty = false;
    if (command == "delete") {
      if (m.empty()) empty = true;
      else {
        sum -= m.begin()->first;
        --size;
        --m.begin()->second;
        if (m.begin()->second == 0) m.erase(m.begin());
        if (m.empty()) empty = true;
      }
    }
    else {
      int x;
      cin >> x;
      sum += x;
      ++size;
      auto it = m.find(x);
      if (it == m.end()) m.insert(make_pair(x, 1));
      else ++it->second;
    }
    if (empty) cout << "no elements" << endl;
    else {
      double avg = sum / size;
      cout << "minimum: " << m.begin()->first << ", maximum: " << m.rbegin()->first << ", average: " << avg << endl;
    }
  }
}
