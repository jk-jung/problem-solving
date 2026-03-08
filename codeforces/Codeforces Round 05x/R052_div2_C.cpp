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

string s;
int idx, r;

vector<string> go() {
  string name;
  while (isupper(s[idx]))
    name += s[idx++];

  vector<string> children;

  char op = s[idx++];
  if (op == ':') {
    do {
      for (auto x : go())
        children.pb(x);
    } while (s[idx++] == ',');
  }
  for (auto x : children)
    r += x == name;
  children.pb(name);
  return children;
}

void solve() {
  cin >> s;
  go();
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
