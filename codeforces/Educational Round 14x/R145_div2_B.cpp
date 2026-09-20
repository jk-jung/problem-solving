#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

using ll = long long;

void solve() {
  ll n;
  cin >> n;

  ll t = sqrt(n);
  while (t * t < n)
    t++;
  cout << t - 1 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int test_case;
  cin >> test_case;
  while (test_case--) {
    solve();
  }
}
