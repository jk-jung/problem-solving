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

ll v[2222][2222];
pi pos[2222 * 2222];
void solve() {
  ll n;
  cin >> n;

  cout << v[pos[n].F][pos[n].S] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 1, c = 0; i <= 2023; i++) {
    for (int j = 1, y = i; j <= i; j++, y--) {
      v[y][j] = ++c;
      pos[c] = {y, j};
    }
  }
  for (int i = 1; i <= 2023; i++) {
    for (int j = 1; j <= 2023; j++) {
      v[i][j] = v[i][j] * v[i][j] + v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
    }
  }

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
