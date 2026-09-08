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

int d[1 << 20];
void solve() {
  string s;
  cin >> s;
  int n = s.size();

  for (int i = 1; i < n; i++) {
    int j = d[i - 1];
    while (j > 0 && s[j] != s[i])
      j = d[j - 1];
    d[i] = s[j] == s[i] ? j + 1 : j;
  }

  if ((d[n - 1] > n / 2)) {
    cout << "YES\n";
    cout << s.substr(0, d[n - 1]) << endl;
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
