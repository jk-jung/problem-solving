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

int a, i;
string s;

int read_a() {
  i += 3;
  return s[i - 3] == 'a' ? 0 : 1;
}

int read_k() {
  int mul = 1, r = 0;
  if (!isdigit(s[i]))
    return 1;
  while (isdigit(s[i]))
    r = r * 10 + (s[i++] - '0');
  i++;
  return mul * r;
}

struct Item {
  int mul, k, x;
  int key() const { return mul * (k * (a + x + 1)) - mul * (k * (a + x)); }
  int v() const { return mul * (k * (a + x)); }
  bool operator<(const Item &o) const { return key() > o.key(); }
};
void solve() {
  cin >> a >> s;

  int r = 0, mul = 1;
  vector<Item> v;
  for (; i < s.size();) {
    int k = read_k();
    int x = read_a();
    v.pb({mul, k, x});

    if (i < s.size()) {
      mul = (s[i++] == '-') ? -1 : 1;
    }
  }
  while (!v.empty()) {
    sort(v.begin(), v.end());
    r += v.back().v();
    v.pop_back();
    a++;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
