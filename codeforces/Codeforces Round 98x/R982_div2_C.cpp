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
  int n;
  cin >> n;
  vector<ll> v(n);
  vector<pair<ll, ll>> t;
  set<ll> s;
  s.insert(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    t.pb({v[i] + i, v[i] + i + i});
  }
  sort(t.begin(), t.end());
  for (auto [x, y] : t) {
    if (s.find(x) != s.end()) {
      s.insert(y);
    }
  }

  cout << *s.rbegin() << endl;
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
