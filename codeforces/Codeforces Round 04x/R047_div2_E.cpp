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

ll b, c;
vector<ll> ck;
vi ck2;
int cnt[10000005];
void solve() {
  cin >> b >> c;
  for (ll i = 0; i <= 5000005 * 2; i += 2) {
    ll t = i * i;
    ck.pb(t);
    ck2.pb(int(i));
  }

  ll tot = 0;

  for (ll i = 2; i <= b * 2; i += 2) {
    ll t = i * i;
    ll s = max(t - 4 * c, 0ll);
    ll e = t - 4;

    if (e < s)
      continue;

    tot += ((e - s) / 4 + 1) * 2;

    int s_idx = lower_bound(ck.begin(), ck.end(), s) - ck.begin();
    int e_idx = upper_bound(ck.begin(), ck.end(), e) - ck.begin();
    for (int j = s_idx; j < e_idx; j++) {
      int val = ck2[j];
      if (++cnt[i - val] >= 2)
        tot--;
      if (++cnt[i + val] >= 2)
        tot--;
    }
  }

  cout << tot << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
