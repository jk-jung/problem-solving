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

ll A, B, N;
bool lose(ll a, ll b) {
  if (b == 1 && a * a >= N) {
    return (N - a) % 2 == 0;
  }
  ll t = 1;
  for (int i = 0; i < b && t <= N; i++, t *= a)
    ;
  return t >= N;
}
map<pair<ll, ll>, int> d;

int go(ll a, ll b) {
  if (a == 1 && b > 30)
    return 2;

  auto k = make_pair(a, b);
  if (d.count(k))
    return d[k];

  int r1 = lose(a + 1, b) ? 0 : (go(a + 1, b) ^ 1);
  int r2 = lose(a, b + 1) ? 0 : (go(a, b + 1) ^ 1);
  if (r1 == 1 || r2 == 1)
    return d[k] = 1;
  if (r2 >= 2)
    return d[k] = 2;
  return d[k] = 0;
}

void solve() {
  cin >> A >> B >> N;

  int r = go(A, B);
  if (r == 2)
    cout << "Missing";
  else if (r == 0)
    cout << "Stas";
  else
    cout << "Masha";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
