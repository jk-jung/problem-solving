#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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

bool ck(string a, string c, string d) {
  string x = a;
  for (int i = 1; i <= 8; i++) {
    if (x[0] == 'h')
      break;
    x[0]++;
    if (x == c)
      break;
    if (x == d)
      return false;
  }
  x = a;
  for (int i = 1; i <= 8; i++) {
    if (x[0] == 'a')
      break;
    x[0]--;
    if (x == c)
      break;
    if (x == d)
      return false;
  }

  x = a;
  for (int i = 1; i <= 8; i++) {
    if (x[1] == '8')
      break;
    x[1]++;
    if (x == c)
      break;
    if (x == d)
      return false;
  }
  x = a;
  for (int i = 1; i <= 8; i++) {
    if (x[1] == '1')
      break;
    x[1]--;
    if (x == c)
      break;
    if (x == d)
      return false;
  }
  return true;
}

bool can(string a, string b, string c, string d) {
  if (a != d) {
    if (!ck(a, c, d))
      return false;
  }
  if (b != d) {
    if (!ck(b, c, d))
      return false;
  }
  if (c != d) {
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0)
          continue;
        string t = c;
        t[0] += i;
        t[1] += j;
        if (t == d)
          return false;
      }
    }
  }
  return true;
}

void solve() {
  string a, b, c, d;
  cin >> a >> b >> c >> d;

  if (can(a, b, c, d)) {
    cout << "OTHER" << endl;
    return;
  }

  bool ok = false;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0)
        continue;
      if (d[0] == 'a' && i == -1)
        continue;
      if (d[0] == 'h' && i == 1)
        continue;
      if (d[1] == '1' && j == -1)
        continue;
      if (d[1] == '8' && j == 1)
        continue;
      d[0] += i;
      d[1] += j;

      if (can(a, b, c, d)) {
        ok = true;
      }

      d[0] -= i;
      d[1] -= j;
    }
  }
  cout << (ok ? "OTHER" : "CHECKMATE") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
