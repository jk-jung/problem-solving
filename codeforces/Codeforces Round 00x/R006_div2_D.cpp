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

int n, a, b;
int h[100];

map<vi, vi> mem[11];

vi dfs(int who, vi st) {
  if (who == st.size()) {
    for (int x : st)
      if (x > 0)
        return {-1};
    return {};
  }
  if (mem[who].count(st))
    return mem[who][st];

  int min_cnt = 0;
  int max_cnt = (st[who] + a - 1) / a;
  if (who > 0)
    max_cnt = max(max_cnt, (st[who - 1] + b - 1) / b);
  if (who < st.size() - 1)
    max_cnt = max(max_cnt, (st[who + 1] + b - 1) / b);
  if (who > 0 && st[who - 1] > 0)
    min_cnt = (st[who - 1] + b - 1) / b;

  vi r = {-1};
  for (int cnt = min_cnt; cnt <= max_cnt; cnt++) {
    vi nxt = st;
    nxt[who] = max(0, st[who] - cnt * a);
    if (who > 0)
      nxt[who - 1] = max(0, st[who - 1] - cnt * b);
    if (who < nxt.size() - 1)
      nxt[who + 1] = max(0, st[who + 1] - cnt * b);

    vi cur = vi(cnt, who);
    for (int x : dfs(who + 1, nxt)) {
      if (x == -1)
        goto next;
      cur.pb(x);
    }

    if (r[0] == -1 || cur.size() < r.size())
      r = cur;
  next:;
  }
  return mem[who][st] = r;
}

void solve() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++)
    cin >> h[i], h[i]++;

  vi r;
  while (h[1] > 0) {
    h[1] -= b;
    h[2] -= a;
    h[3] -= b;
    r.pb(2);
  }
  while (h[n] > 0) {
    h[n] -= b;
    h[n - 1] -= a;
    h[n - 2] -= b;
    r.pb(n - 1);
  }

  vi st;
  for (int i = 2; i <= n - 1; i++)
    st.pb(max(0, h[i]));

  vi r2 = dfs(0, st);
  for (int x : r2)
    r.pb(x + 2);

  cout << r.size() << endl;
  for (int x : r)
    cout << x << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
