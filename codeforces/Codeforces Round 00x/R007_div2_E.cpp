#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int n;
map<string, string> t;
map<string, string> ck;

string name;
vector<string> st;

string pop() {
  string x = st.back();
  st.pop_back();
  return x;
}

void proces_name(string y = "") {
  if (y.empty()) {
    while (!name.empty() && name.back() == ' ')
      name.pop_back();
    reverse(name.begin(), name.end());
    while (!name.empty() && name.back() == ' ')
      name.pop_back();
    reverse(name.begin(), name.end());
    if (name.empty())
      return;
    y = "X";
    if (ck.count(name))
      y = ck[name];

    name.clear();
  }

  if (!st.empty() && (st.back() == "*" || st.back() == "/")) {
    string op = pop();
    string x = pop();
    if (y == "S" || x == "S" || x == "P" || y == "P")
      st.pb("S");
    else if (op == "/" && y == "M")
      st.pb("S");
    else
      st.pb("M");
  } else {
    st.pb(y);
  }
}

string proces_parenthesis() {
  string y;
  while (st.back() != "(") {
    y = pop();
    string op = pop();

    if (op == "(")
      break;
    string x = pop();
    if (op == "-" && y == "P")
      y = "S";
    st.pb((y == "S" || x == "S") ? "S" : "X");
  }

  if (y.empty())
    assert(0);
  return y == "S" ? "S" : "X";
}

string check(string s) {
  name.clear();
  st.clear();

  for (char x : s) {
    if (x == '+' || x == '-') {
      proces_name();
      st.pb(string(1, x));
    } else if (x == '*' || x == '/') {
      proces_name();
      st.pb(string(1, x));
    } else if (x == '(') {
      proces_name();
      st.pb("(");
    } else if (x == ')') {
      proces_name();
      string y = proces_parenthesis();
      proces_name(y);
    } else {
      name += x;
    }
  }
  proces_name();

  for (auto x : st)
    if (x == "S")
      return "S";
  if (st.size() == 1)
    return st[0];

  for (int i = 1; i < st.size(); i++) {
    if (st[i - 1] == "-" && st[i] == "P")
      return "S";
  }

  return "P";
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    string name, value;
    while (true) {
      cin >> s;
      if (s.find("define") != string::npos) {
        cin >> name;
        getline(cin, value);
        t[name] = value;
        break;
      }
    }

    ck[name] = check(value);
  }
  string r;
  getline(cin, r);
  cout << (check(r) == "S" ? "Suspicious" : "OK") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
