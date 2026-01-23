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

map<int, vi> idx;
void solve() {
  int n;
  cin >> n;
  vi r(n), c;
  for (int i = 0, x; i < n; i++)
    cin >> x, idx[x].pb(i);

  int m = (*idx.rbegin()).first;
  int last = 1 << 30;
  for (int i = 1; i <= m; i++) {
    vi &v = idx[i];
    if (v.size() > last) {
      cout << -1;
      return;
    }

    for (int j = 0; j < v.size(); j++) {
      r[v[j]] = j + 1;
    }
    last = v.size();
  }

  cout << idx[1].size() << endl;
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
