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

ll m;

ll mod(string &x) {
  ll r = 0;
  for (char x : x) {
    r = (r * 10 + (x - '0')) % m;
  }
  return r;
}

void minus_one(string &x) {
  int n = x.size();
  x[n - 1]--;
  for (int i = n - 1; i >= 0; i--) {
    if (x[i] < '0') {
      x[i] += 10;
      x[i - 1]--;
    }
  }
}

bool is_odd(string &x) { return x[0] % 2 == 1; }

void half(string &x) {
  int n = x.size();
  int carry = 0;
  for (int i = n - 1; i >= 0; i--) {
    int a = x[i] - '0' + carry * 10;
    carry = a % 2;
    x[i] = a / 2 + '0';
  }
  while (!x.empty() && x.back() == '0')
    x.pop_back();
}

ll big_pow(ll x, string &y) {
  ll r = 1;
  ll cur = x;

  reverse(y.begin(), y.end());

  for (char x : y) {
    ll k = x - '0';
    for (int j = 0; j < k; j++)
      r = (r * cur) % m;
    ll nxt = 1;
    for (int i = 0; i < 10; i++)
      nxt = (nxt * cur) % m;
    cur = nxt;
  }
  return r;
}

void solve() {
  string b, n;
  cin >> b >> n >> m;

  // CNT = (b - 1) * (b ^ (n - 1)) % c
  //         x        y      z

  ll y = mod(b);
  ll x = (y - 1 + m) % m;
  minus_one(n);

  ll z = big_pow(y, n);
  ll r = (x * z) % m;
  if (r == 0)
    r = m;
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
