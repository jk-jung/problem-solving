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

map<string, vi> d;

vi sc = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

bool sf(vi &a, vi &b) {
  vi x(a.begin() + 1, a.end());
  vi y(b.begin() + 1, b.end());
  return x > y;
}

bool sf2(vi &a, vi &b) { return a > b; }

void solve() {

  int n;
  cin >> n;

  while (n--) {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      string s;
      cin >> s;
      if (d.find(s) == d.end())
        d[s] = vi(100, 0);

      d[s][i + 2]++;
      if (i < sc.size())
        d[s][1] += sc[i];
      if (i == 0)
        d[s][0]++;
    }
  }

  vector<vi> v;
  for (auto &[x, y] : d)
    v.pb(y);
  sort(v.begin(), v.end(), sf);
  vi xx = v[0];
  sort(v.begin(), v.end(), sf2);
  vi yy = v[0];

  string r0, r1;
  for (auto &[x, y] : d) {
    if (y == xx)
      r0 = x;
    if (y == yy)
      r1 = x;
  }
  cout << r0 << endl << r1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
