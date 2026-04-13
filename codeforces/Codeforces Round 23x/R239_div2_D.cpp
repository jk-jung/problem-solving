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

int n;
int a[1005];
int r[1005];
int d[1005];
int mod = 1000000007;

void add(int &a, int b) {
  a += b;
  if (a >= mod)
    a -= mod;
}
void solve() {
  memset(d, -1, sizeof(d));
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  d[1] = 1;
  for (int i = 1; i <= n; i++) {
    d[i] = 1;
    for (int j = a[i]; j < i; j++) {
      add(d[i], d[j]);
      add(d[i], 1);
    }
  }
  int r = 2;

  for (int i = 2; i <= n; i++) {
    add(r, d[i]);
    add(r, 1);
  }

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
