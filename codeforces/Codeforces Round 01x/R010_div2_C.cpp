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

ll c[55];
void solve() {
  int n;
  cin >> n;

  ll r = 0;
  for (int i = 1; i <= n; i++)
    c[i % 9]++;
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < 9; k++) {
      r += c[k] * c[(i * k) % 9];
    }
    r -= n / i;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
