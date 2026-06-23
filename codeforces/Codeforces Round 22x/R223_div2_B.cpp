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
  vi v(n), used(n);
  for (int &x : v)
    cin >> x;

  sort(v.begin(), v.end());

  vi r;
  for (int i = 0; i < n; i++) {
    if (r.empty() || r.back() < v[i]) {
      r.pb(v[i]);
      used[i] = 1;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (used[i])
      continue;
    if (r.back() > v[i]) {
      r.pb(v[i]);
      used[i] = 1;
    }
  }
  cout << r.size() << endl;
  for (int x : r)
    cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
