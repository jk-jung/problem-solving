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

string f(string a) {
  string t = a;
  string r = a;
  for (int i = 0; i < a.size(); i++) {
    r = r.substr(1) + r[0];
    if (r < t)
      t = r;
  }
  return t;
}

void solve() {
  int n;
  cin >> n;
  set<string> s;
  for (int i = 0; i < n; i++) {
    string a, b, c;
    if (i)
      cin >> c;
    cin >> a >> b;
    a += b[1];
    a += b[0];
    s.insert(f(a));
  }
  cout << s.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
