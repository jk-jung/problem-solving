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

ll mod = 1000000009;
ll k = 1000000007;
string s;
ll n;
ll d[5555555];
ll a[5555555];
ll b[5555555];
ll p[5555555];

bool is_pal(int x) {
  int m = x / 2;
  if (m == 0)
    return true;

  ll v1 = (a[m - 1] * p[n - x]) % mod;
  ll v2 = n == x ? b[m - 1] : (b[n - x + m - 1] - b[n - x - 1] + mod) % mod;
  return v1 == v2;
}
void solve() {
  cin >> s;
  n = s.size();

  p[0] = 1;
  for (int i = 0; i < n; i++)
    p[i + 1] = p[i] * k % mod;

  char base = 0;
  a[0] = s[0] - base;
  b[0] = s.back() - base;
  for (int i = 1; i < n; i++) {
    a[i] = (a[i - 1] + (s[i] - base) * p[i]) % mod;
    b[i] = (b[i - 1] + (s[n - i - 1] - base) * p[i]) % mod;
  }

  d[0] = 1;
  ll r = 1;
  for (int i = 1; i < n; i++) {
    if (is_pal(i + 1)) {
      d[i] = d[(i + 1) / 2 - 1] + 1;
      r += d[i];
    }
  }

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
