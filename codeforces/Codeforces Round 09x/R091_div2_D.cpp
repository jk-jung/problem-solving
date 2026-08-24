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
  string s;
  cin >> n >> k >> s;

  for (int i = 1; i < n; i++) {
    if (s[i - 1] == '4' && s[i] == '7') {
      if (i % 2 == 1) {
        if (i + 1 < n && s[i + 1] == '7')
          k %= 2;
        if (k > 0)
          s[i] = '4', k--;
      } else {
        if (i - 2 >= 0 && s[i - 2] == '4')
          k %= 2;
        if (k > 0)
          s[i - 1] = '7', k--;
      }
    }

    if (k == 0)
      break;
  }

  cout << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
