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

ll d[2005][2005];
void solve() {
  ll n, k;
  cin >> k >> n;

  d[0][1] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      for (int x = j; x <= k; x += j) {
        d[i + 1][x] = (d[i + 1][x] + d[i][j]) % mod;
      }
    }
  }
  ll r = 0;
  for (int i = 1; i <= k; i++) {
    r = (r + d[n][i]) % mod;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
