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

int r[2000000];
void solve() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll g = gcd(a, b);
  a /= g;
  b /= g;

  double p = 1, q = 1;
  ll t = a + b;

  for (int i = 1; i < t - 1; i++) {
    if (p / a < q / b)
      p++, r[i] = 1;
    else
      q++;
  }

  while (n--) {
    ll x;
    cin >> x;

    x %= t;
    if (x == 0 || x == t - 1) {
      cout << "Both" << endl;
    } else {
      cout << (r[x] == 1 ? "Vanya" : "Vova") << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
