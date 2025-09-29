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
string s, r;
ll d[55][55];
int f[55][55];
ll base[20];

ll go(int a, int b) {
  if (a > n || b > n)
    return -(1ll << 60);
  if (a + b == n * 2)
    return 0;

  ll &r = d[a][b];
  if (r != -1)
    return r;

  int k = s[a + b] - '0';
  ll r1 = go(a + 1, b) + base[a] * k;
  ll r2 = go(a, b + 1) + base[b] * k;
  if (r1 >= r2)
    f[a][b] = 1;
  else
    f[a][b] = 2;
  return r = max(r1, r2);
}

void trace(int a, int b) {
  if (a + b == n * 2)
    return;
  if (f[a][b] == 1) {
    r += "M";
    trace(a + 1, b);
  } else {
    r += "H";
    trace(a, b + 1);
  }
}
void solve() {
  cin >> n >> s;
  memset(d, -1, sizeof(d));
  reverse(s.begin(), s.end());
  base[0] = 1;
  for (int i = 1; i < 18; i++)
    base[i] = base[i - 1] * 10;

  go(0, 0);
  trace(0, 0);
  reverse(r.begin(), r.end());

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
