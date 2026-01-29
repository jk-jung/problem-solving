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
  int n;
  cin >> n;
  vi a(n);
  vi b(n);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;
  vector<pi> r;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i])
      continue;

    for (int j = i; j < n; j++) {
      if (a[i] == b[j]) {
        while (i < j) {
          swap(b[j], b[j - 1]);
          r.pb(mp(j, j + 1));
          j--;
        }
        break;
      }
    }
  }
  cout << r.size() << endl;
  for (auto [x, y] : r)
    cout << x << " " << y << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
