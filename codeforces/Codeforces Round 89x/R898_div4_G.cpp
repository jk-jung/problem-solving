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

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  vi v;
  int c = 0, tot = 0;
  char x = 'A';
  for (int i = 0; i < n; i++) {
    char y = s[i];
    if (y == 'B') {
      if (c)
        v.pb(c);
      c = 0;
    } else
      c++, tot++;
  }
  if (c)
    v.pb(c);

  if (s[0] == 'B' || s[n - 1] == 'B' || s.find("BB") != -1) {
    cout << tot << endl;
  } else {
    sort(v.begin(), v.end());
    cout << tot - v[0] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
