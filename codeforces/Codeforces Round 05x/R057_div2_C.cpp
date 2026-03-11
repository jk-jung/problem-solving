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

char f(int x) {
  if (x < 10)
    return x + '0';
  return x - 10 + 'A';
}

char g(char x) {
  if ('0' <= x && x <= '9')
    return x - '0';
  return x - 'A' + 10;
}

map<char, int> R = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                    {'C', 100}, {'D', 500}, {'M', 1000}};

string base = "IXCM ";
string half = "VLD";

void r(ll v) {
  int k = 0;
  vector<string> t;

  while (v) {
    int x = v % 10;
    string cur = string(1, base[k]);
    string nxt = string(1, base[k + 1]);
    string five = string(1, half[k]);

    if (x == 4)
      t.pb(cur + five);
    else if (x == 9)
      t.pb(cur + nxt);
    else {
      string q;
      if (x >= 5)
        q += five, x -= 5;
      while (x--)
        q += cur;
      t.pb(q);
    }
    k++;
    v /= 10;
  }
  reverse(t.begin(), t.end());
  for (auto &x : t)
    cout << x;
  cout << endl;
}

void solve() {
  ll a;
  string b, c;
  cin >> a >> b >> c;
  ll v = 0;

  reverse(c.begin(), c.end());
  for (ll i = 0, b = 1; i < c.size(); i++, b *= a)
    v += g(c[i]) * b;

  if (b == "R") {
    r(v);
  } else {
    if (v == 0) {
      cout << 0 << endl;
      return;
    }
    string r;
    int B = stoi(b);
    while (v) {
      r.pb(f(v % B));
      v /= B;
    }
    reverse(r.begin(), r.end());
    cout << r << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
