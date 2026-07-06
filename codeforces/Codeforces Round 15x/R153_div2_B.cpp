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
  vi v(n);
  for (int &x : v)
    cin >> x;

  vi a = v, b = v;
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());

  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (v[0] != v[i]) {
      swap(v[0], v[i]);
      if (a != v && b != v) {
        cout << "1 " << i + 1 << endl;
        return;
      }
      swap(v[0], v[i]);
      if (++cnt == 4)
        break;
    }
  }
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (v[1] != v[i] && n >= 2) {
      swap(v[1], v[i]);
      if (a != v && b != v) {
        cout << "2 " << i + 1 << endl;
        return;
      }
      swap(v[1], v[i]);
      if (++cnt == 4)
        break;
    }
  }
  cout << "-1" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
