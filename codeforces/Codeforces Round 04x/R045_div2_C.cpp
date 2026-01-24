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

ll SCALE = 3000000;

int check(vi &v, ll a) {
  int pos = 0;
  ll fuel = 0;
  vi t;
  while (t.size() < v.size()) {
    if (pos) {
      t.pb(pos);
      if (t.back() != v[t.size() - 1])
        return 0;
    }
    fuel += a;
    pos += fuel / SCALE;
    fuel %= SCALE;
  }
  if (t == v)
    return pos;
  return 0;
}

void solve() {
  int n;
  cin >> n;
  vi v(n);
  for (int &x : v)
    cin >> x;

  if (n == 1) {
    cout << "not unique" << endl;
    return;
  }

  ll a = v[0] * SCALE;
  set<int> s;

  for (int k = 0; k < SCALE; k++) {
    int t = check(v, a + k);
    if (t) {
      s.insert(t);
      if (s.size() == 2) {
        cout << "not unique" << endl;
        return;
      }
    }
  }
  if (s.size() == 1) {
    cout << "unique" << endl;
    cout << *s.begin() << endl;
    return;
  }
  cout << "not unique" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
