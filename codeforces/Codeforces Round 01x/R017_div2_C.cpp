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

int mod = 51123987;
int n, m;
string s, t;
int d[151][51][51][51];
vi nxt[151];

int go(int pattern, int a, int b, int c) {
  if (a + b + c == n)
    return ab(a - b) <= 1 && ab(b - c) <= 1 && ab(c - a) <= 1;
  if (a > 50 || b > 50 || c > 50)
    return 0;

  int &r = d[pattern][a][b][c];
  if (r != -1)
    return r;
  char x = t[pattern];

  r = go(pattern, a + (x == 'a'), b + (x == 'b'), c + (x == 'c'));
  for (int i : nxt[pattern]) {
    char y = t[i];
    r += go(i, a + (y == 'a'), b + (y == 'b'), c + (y == 'c'));
    if (r >= mod)
      r -= mod;
  }

  return r;
}

void solve() {
  memset(d, -1, sizeof(d));
  cin >> n >> s;

  for (char x : s) {
    if (t.empty() || t.back() != x)
      t += x;
  }
  m = t.size();

  for (int i = 0; i < m; i++) {
    set<char> used;
    for (int j = i + 1; j < m; j++) {
      if (used.count(t[j]) || t[j] == t[i])
        continue;
      used.insert(t[j]);
      nxt[i].pb(j);
    }
  }

  set<char> used;
  int r = 0;
  for (int i = 0; i < m; i++) {
    if (used.count(t[i]))
      continue;
    used.insert(t[i]);
    char x = t[i];
    r = (r + go(i, x == 'a', x == 'b', x == 'c')) % mod;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
