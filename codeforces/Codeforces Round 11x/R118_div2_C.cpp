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

ll mod = 1000000007;
void solve() {
  ll n;
  ll u = 1, d = 0;
  ll x = 3, y = 1;
  cin >> n;

  while (n) {
    if (n % 2) {
      ll u2 = (u * x + d * y) % mod;
      ll d2 = (u * y + d * x) % mod;
      u = u2;
      d = d2;
    }
    ll x2 = (x * x + y * y) % mod;
    ll y2 = x * y * 2 % mod;
    x = x2;
    y = y2;
    n /= 2;
  }
  cout << u << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
