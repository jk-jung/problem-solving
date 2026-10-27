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
  int n, r;
  cin >> n >> r;
  vi v(n);
  int t = 0, o = 0;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (x % 2)
      o++;
    t += x / 2;
  }
  int tt = 0;
  int left = r - t;
  if (o <= left)
    tt += o;
  else
    tt += left * 2 - o;
  cout << t * 2 + tt << endl;
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
