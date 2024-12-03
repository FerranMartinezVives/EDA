#include<iostream>
#include<queue>
using namespace std;

int main() {
  priority_queue<int> cua;
  char op;
  while (cin >> op) {
    if (op == 'S') {
      int x;
      cin >> x;
      cua.push(x);
    }
    else if (op == 'A') {
      if (cua.empty()) cout << "error!" << endl;
      else cout << cua.top() << endl;
    }
    else if (op == 'R') {
      if (cua.empty()) cout << "error!" << endl;
      else cua.pop();
    }
    else if (op == 'I') {
      int x;
      cin >> x;
      if (cua.empty()) cout << "error!" << endl;
      else {
        int n = cua.top() + x;
        cua.pop();
        cua.push(n);
      }
    }
    else { // op == 'D'
      int x;
      cin >> x;
      if (cua.empty()) cout << "error!" << endl;
      else {
        int n = cua.top() - x;
        cua.pop();
        cua.push(n);
      }
    }
  }
}
