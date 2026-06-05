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

string add_comma(string s) {
  string r;
  for (int i = s.size() - 1, k = 0; i >= 0; i--) {
    r += s[i];
    if (++k % 3 == 0)
      r += ',';
  }
  if (r.back() == ',')
    r.pop_back();
  reverse(r.begin(), r.end());
  return r;
}

void solve() {
  string s, r;
  cin >> s;

  bool dot = false;
  int cnt = 0;
  for (char x : s) {
    if (x == '-')
      continue;
    if (x == '.') {
      r = add_comma(r);
      r += '.';
      dot = true;
      continue;
    }
    if (dot) {
      if (cnt < 2) {
        cnt++;
        r += x;
      }
    } else {
      r += x;
    }
  }
  if (!dot) {
    r = add_comma(r);
    r += '.';
  }
  while (cnt < 2)
    r += '0', cnt++;

  r = '$' + r;
  if (s[0] == '-')
    r = '(' + r + ')';

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
