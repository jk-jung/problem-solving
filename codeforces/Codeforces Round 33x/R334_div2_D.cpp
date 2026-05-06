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

ll p, k;
ll mod = 1e9 + 7;

void solve() {
  cin >> p >> k;
  ll r = 1;

  if (k == 0) {
    for (int i = 1; i < p; i++)
      r = (r * p) % mod;
    cout << r << endl;
    return;
  }
  if (k == 1) {
    for (int i = 0; i < p; i++)
      r = (r * p) % mod;
    cout << r << endl;
    return;
  }

  ll cnt = 0, x = 1;
  do {
    cnt++;
    x = k * x % p;
  } while (x != 1);

  cnt = (p - 1) / cnt;
  for (int i = 0; i < cnt; i++)
    r = (r * p) % mod;
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
