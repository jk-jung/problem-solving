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

void solve() {
  ll a, b;
  cin >> a >> b;
  ll r = 0, k = 1;
  while (a || b) {
    int t = 0;
    for (int i = 0; i < 3; i++) {
      if ((a % 3 + i % 3) % 3 == b % 3) {
        t = i;
        break;
      }
    }
    cout << a % 3 << " " << b % 3 << " " << t << endl;
    a /= 3;
    b /= 3;
    r += t * k;
    k *= 3;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
