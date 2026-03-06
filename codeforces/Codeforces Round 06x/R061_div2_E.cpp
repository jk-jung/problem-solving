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

// 2  3  1  7
// 1  3  8  1
// 1  0 -7  6

vi check(vi &c) {
  vi r;
  ll sum = 0;

  priority_queue<pair<ll, int>> q;
  for (int i = 0; i < n; i++) {
    sum += c[i];
    q.push({-sum, i});
  }

  for (int i = 0; i < n; i++) {
    ll dif = c[i];

    while (q.top().S < i)
      q.pop();

    if (-q.top().F >= sum)
      r.pb(i);

    sum += dif;
    q.push({-sum, i + n});
  }
  return r;
}

void solve() {
  cin >> n;
  vi a(n), b(n);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  vi c(n);
  for (int i = 0; i < n; i++)
    c[i] = a[i] - b[i];
  vi d;
  for (int i = n - 1; i >= 0; i--) {
    d.pb(a[i] - b[(i - 1 + n) % n]);
  }
  vi r = check(c);
  vi r1 = check(d);

  for (int x : r1)
    r.pb(n - x - 1);
  sort(r.begin(), r.end());
  r.erase(unique(r.begin(), r.end()), r.end());

  cout << r.size() << endl;
  for (int x : r)
    cout << x + 1 << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
