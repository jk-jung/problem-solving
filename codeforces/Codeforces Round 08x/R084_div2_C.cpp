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
  cin >> n;
  string r, t;
  for (int i = 0; n >= 0; i++) {
    if (n % 7 == 0) {
      string x = t + string(n / 7, '7');
      if (r.empty() || r.size() > x.size())
        r = x;
      else if (r.size() == x.size())
        r = min(r, x);
    }

    n -= 4;
    t += '4';
  }
  cout << (r.empty() ? "-1" : r) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
