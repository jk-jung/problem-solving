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
  int n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (auto &x : v)
    cin >> x;

  int t = 0;
  for (int i = 0; i < n; i++) {
    t = max(t, (int)count(v[i].begin(), v[i].end(), '#'));
  }
  for (int i = 0; i < n; i++) {
    if (count(v[i].begin(), v[i].end(), '#') == t) {
      for (int j = 0; j < m; j++) {
        if (v[i][j] == '#') {
          cout << i + 1 << " " << j + t / 2 + 1 << endl;
          return;
        }
      }
    }
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
