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
  int n, k;
  int c = 0;
  string s;
  cin >> n >> k >> s;
  for (char x : s)
    c += x == 'B';

  if (c == k) {
    cout << "0\n";
    return;
  }

  cout << "1\n";
  for (int i = 0; i < n; i++) {
    if (c > k && s[i] == 'B') {
      if (--c == k) {
        cout << i + 1 << " A\n";
        return;
      }
    }
    if (c < k && s[i] == 'A') {
      if (++c == k) {
        cout << i + 1 << " B\n";
        return;
      }
    }
  }
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
