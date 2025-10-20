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

double x[3], y[3], r[3];
double dx[4] = {0, 1, 0, -1};
double dy[4] = {1, 0, -1, 0};

double t(double a, double b) { return (a - b) * (a - b); }
double f(double X, double Y) {
  double d[3];
  for (int i = 0; i < 3; i++)
    d[i] = sqrt(t(X, x[i]) + t(Y, y[i])) / r[i];
  return t(d[0], d[1]) + t(d[1], d[2]) + t(d[2], d[0]);
}

void solve() {
  for (int i = 0; i < 3; i++)
    cin >> x[i] >> y[i] >> r[i];

  double X = (x[0] + x[1] + x[2]) / 3;
  double Y = (y[0] + y[1] + y[2]) / 3;

  double k = 1;
  double cur;
  for (int _ = 0; _ < 10000; _++) {
    cur = f(X, Y);
    int idx = -1;
    for (int i = 0; i < 4; i++) {
      double nx = X + dx[i] * k;
      double ny = Y + dy[i] * k;
      double nxt = f(nx, ny);
      if (nxt < cur) {
        cur = nxt;
        idx = i;
        X = nx;
        Y = ny;
      }
    }
    if (idx == -1)
      k *= 0.9;
  }
  if (cur > 1e-7)
    return;
  cout << fixed << setprecision(10) << X << " " << Y << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
