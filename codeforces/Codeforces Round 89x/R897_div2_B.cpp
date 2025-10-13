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

void solve() {
  int n;
  string s;
  cin >> n >> s;

  int diff = 0, same = 0, mid = n % 2;
  for (int a = 0, e = n - 1; a < e; a++, e--) {
    if (s[a] != s[e])
      diff++;
    else
      same++;
  }

  for (int i = 0; i <= n; i++) {
    if (i < diff) {
      cout << 0;
    } else {
      int rest = i - diff;
      rest -= min(rest / 2, same) * 2;
      rest -= min(rest, mid);
      cout << (rest == 0 ? 1 : 0);
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
