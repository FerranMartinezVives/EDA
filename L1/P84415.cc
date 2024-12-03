#include<iostream>
#include<map>
using namespace std;

int main() {
  map<string, int> bag;
  string command;
  while (cin >> command) {
    if (command == "store") {
      string w;
      cin >> w;
      auto it = bag.find(w);
      if (it != bag.end()) ++it->second;
      else bag.insert(make_pair(w, 1));
    }
    else if (command == "delete") {
      string w;
      cin >> w;
      auto it = bag.find(w);
      if (it != bag.end()) {
        --it->second;
        if (it->second == 0) bag.erase(it);
      }
    }
    else if (command == "maximum?") {
      if (bag.empty()) cout << "indefinite maximum" << endl;
      else cout << "maximum: " << bag.rbegin()->first << ", " << bag.rbegin()->second << " time(s)" << endl;
    }
    else {  //command == "minimum?"
      if (bag.empty()) cout << "indefinite minimum" << endl;
      else cout << "minimum: " << bag.begin()->first << ", " << bag.begin()->second << " time(s)" << endl;
    }
  }
}
