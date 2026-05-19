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

int d[1005][15][15];
int from[1005][15][15];
string s;
int n;

int go(int pos, int last, int dif) {
  if (pos == n)
    return 1;

  int &r = d[pos][last][dif];
  if (r != -1)
    return r;

  r = 0;
  for (int i = dif + 1; i <= 10; i++) {
    if (s[i - 1] != '1' || i == last)
      continue;

    if (go(pos + 1, i, i - dif)) {
      r = 1;
      from[pos][last][dif] = i;
      return r;
    }
  }
  return r;
}

void print(int pos, int last, int dif) {
  if (pos == n)
    return;

  int i = from[pos][last][dif];
  cout << i << " ";
  print(pos + 1, i, i - dif);
}

void solve() {
  cin >> s >> n;
  vi v;
  for (int i = 0; i < 10; i++) {
    if (s[i] == '1')
      v.pb(i + 1);
  }
  if (v.size() == 0) {
    cout << "NO\n";
    return;
  }
  if (v.size() == 1 && n >= 2) {
    cout << "NO\n";
    return;
  }

  memset(d, -1, sizeof(d));
  int r = go(0, 0, 0);
  if (!r) {
    cout << "NO\n";
    return;
  }

  cout << "YES\n";
  print(0, 0, 0);
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
