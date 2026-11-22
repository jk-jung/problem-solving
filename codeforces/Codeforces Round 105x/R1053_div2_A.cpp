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
  vi v(m);
  for (int &x : v)
    cin >> x;

  int last = -1;
  int cnt = 0;
  for (int i = 1; i < m; i++) {
    if (v[i - 1] + 1 != v[i]) {
      if (v[i] != 1 || (last != -1 && v[i - 1] != last + 1)) {
        cout << "0\n";
        return;
      }
      last = v[i - 1];
    }
  }
  if (last != -1) {
    cout << "1\n";
  } else {
    cout << max(0, n - v.back() + 1) << endl;
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
