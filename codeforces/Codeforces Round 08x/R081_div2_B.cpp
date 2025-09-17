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
int n, k, A;
vector<pi> v;

double r = 0;

void calc() {
  double t = 0;
  for (int i = 0; i < (1 << n); i++) {
    double p = 1, B = 0;
    int cnt = 0;

    for (int j = 0; j < n; j++) {
      double x = min(100, v[j].S);
      if (i >> j & 1) {
        cnt++;
        p *= x / 100.0;
      } else {
        B += v[j].F;
        p *= (100 - x) / 100.0;
      }
    }
    if (cnt * 2 > n)
      t += p;
    else {
      t += p * A / (A + B);
    }
  }
  r = max(r, t);
}

void go(int idx, int candies) {
  if (idx == n) {
    if (candies)
      return;
    return calc();
  }

  int &p = v[idx].S;
  for (int i = 0; i <= candies; i++) {
    p += i * 10;
    go(idx + 1, candies - i);
    p -= i * 10;
  }
}

void solve() {
  cin >> n >> k >> A;
  v.resize(n);
  for (auto &[x, y] : v)
    cin >> x >> y;

  go(0, k);
  cout.precision(10);
  cout << fixed << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
