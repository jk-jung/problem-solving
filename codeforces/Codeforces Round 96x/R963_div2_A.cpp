#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<int> c(4);
    for (int i = 0; i < 4 * n; i++) {
      int d = s[i] - 'A';
      if (0 <= d && d <= 3)
        c[d]++;
    }
    int ans = 0;
    for (int &x : c)
      ans += min(n, x);
    cout << ans << '\n';
  }
}