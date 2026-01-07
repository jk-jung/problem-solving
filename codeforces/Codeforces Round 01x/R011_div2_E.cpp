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

double process(string t) {
  double s = 0, e = 1e8, r = 0;
  for (int _ = 0; _ < 43; _++) {
    // set p
    // p <= O / (O + X)
    // pO + pX <= O
    // (1 - p)O - pX >= 0
    double m = (s + e) / 2;
    double p = m / 1e8;
    double c_even = -p, c_odd = 0;
    for (char x : t) {
      if (x == 'X') {
        double n_even = max(c_even - p - p, c_odd - p);
        double n_odd = max(c_even - p, c_odd - p - p);
        c_even = n_even;
        c_odd = n_odd;
      } else if (x == 'L') {
        double n_even = max(c_even - p - p, c_odd - p) + 1;
        double n_odd = max(c_even - p, c_odd - p - p);
        c_even = n_even;
        c_odd = n_odd;
      } else {
        double n_even = max(c_even - p - p, c_odd - p);
        double n_odd = max(c_even - p, c_odd - p - p) + 1;
        c_even = n_even;
        c_odd = n_odd;
      }
    }
    double c = max(c_even - p, c_odd);
    if (c >= 0)
      r = m, s = m;
    else
      e = m;
  }
  return r;
}

void solve() {
  string k, t;
  cin >> k;
  for (char c : k) {
    if (!t.empty() && t.back() == c && c != 'X')
      t += 'X';
    t += c;
  }
  double r = 0;
  if (t[0] == t.back() && t[0] != 'X')
    r = max(process("X" + t), process(t + "X"));
  else
    r = process(t);
  cout << fixed << setprecision(6) << int(r + 1e-4) / 1e6 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
