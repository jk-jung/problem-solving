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
string s;

int calc(string a, string &b) {
  int r = 0;
  while (true) {
    bool ok = true;
    for (int i = 1; i < n; i++) {
      if (a[i - 1] == a[i]) {
        ok = false;
        r++;
        a[i - 1] = b[i - 1];
        a[i] = b[i];
      }
    }
    if (ok)
      break;
  }
  if (a != b)
    return 1 << 30;
  return r;
}

void solve() {

  cin >> n >> s;
  string a, b;
  while (a.size() < n) {
    a += "10";
    b += "01";
  }
  a = a.substr(0, n);
  b = b.substr(0, n);

  cout << min(calc(s, a), calc(s, b)) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
