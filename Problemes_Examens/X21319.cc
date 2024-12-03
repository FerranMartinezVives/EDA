#include<iostream>
#include<vector>
#include<map>
using namespace std;

using VB = vector<bool>;
using VC = vector<char>;
using VI = vector<int>;
using PSI = pair<string, int>;
using PSB = pair<string, bool>;
using PSS = pair<string, string>;
using TSPSS = pair<string, PSS>;

map<string, int> map_input, map_output, map_not, map_and, map_or;
VB vec_output, vec_input;

int main() {
  string id, s;
  cin >> id;
  int i = 0;
  while (cin >> s and s != "END") {
    map_output.insert(PSI(s, i));
    vec_output.push_back(false);
    ++i;
  }
  cin >> id;
  i = 0;
  while (cin >> s and s != "END") {
    map_input.insert(PSI(s, i));
    vec_input.push_back(false);
    ++i;
  }
  
}
