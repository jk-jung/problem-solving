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

typedef pair<double, double> pd;
typedef pair<pd, pd> line;

line read_line() {
  line r;
  cin >> r.F.F >> r.F.S >> r.S.F >> r.S.S;
  return r;
}

bool is_ver(line a) { return a.F.F == a.S.F && a.F.S != a.S.S; }
bool is_hor(line a) { return a.F.S == a.S.S && a.F.F != a.S.F; }

map<pd, int> ck;

bool check(line a, line b) {
  if (!(is_ver(a) && is_hor(b)) && !(is_ver(b) && is_hor(a)))
    return false;

  bool ok = false;
  if (a.F == b.F || a.F == b.S)
    ck[a.F]++, ok = true;
  if (a.S == b.F || a.S == b.S)
    ck[a.S]++, ok = true;
  return ok;
}

void solve() {
  vector<line> v;
  v.pb(read_line());
  v.pb(read_line());
  v.pb(read_line());
  v.pb(read_line());

  sort(v.begin(), v.end());
  do {
    for (int i = 0; i < 4; i++) {
      line a = v[i];
      line b = v[(i + 1) % 4];
      if (!check(a, b))
        goto NO;
    }
    if (ck.size() != 4)
      goto NO;
    cout << "YES" << endl;
    return;
  NO:;

  } while (next_permutation(v.begin(), v.end()));
  cout << "NO" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
