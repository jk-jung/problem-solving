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

int n;

void check(int x, vi &v, bool zero = false) {
  int last = 1 << 30;
  int g = zero ? 0 : 1 << 30;
  for (int i = 0; i < n; i++) {
    if (i == x)
      continue;

    if (last != (1 << 30)) {
      if (g == (1 << 30))
        g = v[i] / last;

      if (last * g != v[i]) {
        return;
      }
    }
    last = v[i];
  }
  if (x == -1) {
    cout << "0\n";
  } else
    cout << "1\n";
  exit(0);
}

void check_zero(vi &zero, vi &v) {
  vi non;
  for (int i = 0; i < n; i++)
    if (v[i])
      non.pb(i);

  if (non.size() > 5) {
    cout << "2\n";
    return;
  }

  for (int i = 0; i < non.size(); i++) {
    check(non[i], v, true);
  }

  cout << "2\n";
  return;
}

void solve() {

  cin >> n;
  vi v(n);
  for (int &x : v)
    cin >> x;

  vi zero;
  for (int i = 0; i < n; i++) {
    if (v[i] == 0)
      zero.pb(i);
  }
  if (zero.size() == n) {
    cout << "0\n";
    return;
  }
  if (zero.size() == n - 1) {
    if (v[0] == 0)
      cout << "1\n";
    else
      cout << "0\n";
    return;
  }
  if (zero.size() == 1) {
    check(zero[0], v);
    reverse(v.begin(), v.end());
    check(n - zero[0] - 1, v);
    cout << "2\n";
    return;
  } else if (zero.size() >= 2) {
    check_zero(zero, v);
    return;
  }
  map<int, int> ck;
  for (int i = 1; i < n; i++) {
    int t = v[i] / v[i - 1];
    ck[t]++;
  }
  int g = ck.begin()->F;
  for (auto [k, v] : ck) {
    if (ck[g] < v) {
      g = k;
    }
  }

  vi no;

  for (int i = 1; i < n; i++) {
    if (v[i - 1] * g != v[i]) {
      no.pb(i - 1);
      no.pb(i);
    }
  }
  sort(no.begin(), no.end());
  no.erase(unique(no.begin(), no.end()), no.end());

  if (no.empty()) {
    cout << "0\n";
    return;
  }
  if (no.size() > 20) {
    cout << "2\n";
    return;
  }

  if (n < 20) {
    no.clear();
    for (int i = 0; i < n; i++)
      no.pb(i);
  }

  for (int x : no) {
    check(x, v);
  }
  reverse(v.begin(), v.end());
  check(-1, v);
  for (int x : no) {
    check(x, v);
  }

  cout << "2\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
