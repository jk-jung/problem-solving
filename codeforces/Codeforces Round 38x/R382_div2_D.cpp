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

bool check(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  ll n;
  cin >> n;
  int r = 0;
  if (n % 2 == 0) {
    cout << (n == 2 ? 1 : 2) << endl;
    return;
  }
  if (check(n)) {
    cout << 1 << endl;
  } else if (check(n - 2)) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
