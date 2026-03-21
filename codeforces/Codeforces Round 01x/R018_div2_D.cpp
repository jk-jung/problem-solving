#include <algorithm>
#include <array>
#include <bitset>
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

bitset<3000> d[5005];
bool vis[5005];
pi trans[5005];
vi q[5005];
int n;
bitset<3000> r2;

void add(bitset<3000> &a, int x) {
  while (a.test(x))
    a.reset(x++);
  a.set(x);
}

bool is_large(bitset<3000> &a, bitset<3000> &b) {
  bitset<3000> diff = a ^ b;
  if (diff.none())
    return false;
  int top = 2999;
  while (top >= 0 && !diff.test(top))
    top--;
  return a.test(top);
}

void go(int i) {
  if (i == n || vis[i])
    return;

  go(i + 1);

  auto [nxt, x] = trans[i];
  if (nxt != -1) {
    go(nxt + 1);
    r2 = d[nxt + 1];
    add(r2, x);
    if (is_large(r2, d[i + 1]))
      d[i] = r2;
    else
      d[i] = d[i + 1];
  } else {
    d[i] = d[i + 1];
  }
  vis[i] = true;
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    trans[i] = {-1, -1};

  for (int i = 0; i < n; i++) {
    string op;
    int x;
    cin >> op >> x;
    if (op == "win") {
      q[x].pb(i);
    } else {
      while (!q[x].empty()) {
        trans[q[x].back()] = {i, x};
        q[x].clear();
      }
    }
  }

  go(0);
  bitset<3000> r = d[0];

  vector<int> cur;
  vector<int> rst;
  cur.pb(1);
  for (int i = 0; i < 3000; i++) {
    if (r.test(i)) {
      while (rst.size() < cur.size())
        rst.pb(0);
      int carry = 0;
      for (int j = 0; j < cur.size(); j++) {
        rst[j] = (rst[j] + cur[j] + carry);
        carry = rst[j] / 10;
        rst[j] %= 10;
      }
      if (carry)
        rst.pb(carry);
      r.reset(i);
    }
    if (r.none())
      break;

    int carry = 0;
    for (int i = 0; i < cur.size(); i++) {
      cur[i] = cur[i] * 2 + carry;
      carry = cur[i] / 10;
      cur[i] %= 10;
    }
    if (carry)
      cur.pb(carry);
  }
  if (rst.empty())
    rst.pb(0);
  reverse(rst.begin(), rst.end());
  for (int x : rst)
    cout << x;
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
