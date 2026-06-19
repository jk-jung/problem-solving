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

ll mod = 1000000007;

int st(int t, int x, int y) {
  if (x >= '0')
    x -= '0';
  if (y >= '0')
    y -= '0';
  if (x == y)
    return t;
  return t | (1 << (x > y ? 0 : 1));
}

void add(ll &a, ll b) {
  a += b;
  if (a >= mod)
    a -= mod;
}

void solve() {
  int n;
  string a, b;
  cin >> n >> a >> b;
  vector<ll> d(4);

  d[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<ll> d2(4);

    if (a[i] == '?') {
      if (b[i] == '?') {
        for (int q = 0; q < 4; q++) {
          for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
              int t = st(q, x, y);
              add(d2[t], d[q]);
            }
          }
        }
      } else {
        for (int q = 0; q < 4; q++) {
          for (int x = 0; x < 10; x++) {
            int t = st(q, x, b[i]);
            add(d2[t], d[q]);
          }
        }
      }
    } else if (b[i] == '?') {
      for (int q = 0; q < 4; q++) {
        for (int y = 0; y < 10; y++) {
          int t = st(q, a[i], y);
          add(d2[t], d[q]);
        }
      }
    } else {
      for (int q = 0; q < 4; q++) {
        int t = st(q, a[i], b[i]);
        add(d2[t], d[q]);
      }
    }

    d = d2;
  }
  cout << d[3] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
