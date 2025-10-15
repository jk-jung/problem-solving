#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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
  ll n;
  cin >> s >> n;

  vi v;
  vector<pair<char, int>> st;
  for (int i = 0; i < s.size(); i++) {
    if (st.empty() || st.back().F <= s[i]) {
      st.pb({s[i], i});
    } else {
      while (!st.empty() && st.back().F > s[i]) {
        v.pb(st.back().S);
        st.pop_back();
      }
      st.pb({s[i], i});
    }
  }

  while (!st.empty()) {
    v.pb(st.back().S);
    st.pop_back();
  }

  int m = s.size();
  vi used(m, 0);
  for (int i = 0; i < m; i++) {
    int len = m - i;
    if (n <= len) {
      for (int k = 0; k < m; k++) {
        if (used[k])
          continue;
        if (--n == 0) {
          cout << s[k];
          return;
        }
      }
    }
    used[v[i]] = 1;
    n -= len;
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
