#include<iostream>
#include<map>
using namespace std;

int main() {
  map<string, int> registre;
  string nom;
  while (cin >> nom) {
    string op;
    cin >> op;
    if (op == "enters") {
      if (registre.find(nom) != registre.end()) cout << nom << " is already in the casino" << endl;
      else registre.insert(make_  pair(nom, 0));
    }
    else if (op == "leaves") {
      auto it = registre.find(nom);
      if (it == registre.end()) cout << nom << " is not in the casino" << endl;
      else {
        cout << nom << " has won " << it->second << endl;
        registre.erase(nom);
      }
    }
    else {  //op == "wins"
      int x;
      cin >> x;
      auto it = registre.find(nom);
      if (it == registre.end()) cout << nom << " is not in the casino" << endl;
      else it->second += x;
    }
  }
  cout << "----------" << endl;
  auto it = registre.begin();
  while (it != registre.end()) {
    cout << it->first << " is winning " << it->second << endl;
    ++it;
  }
}
