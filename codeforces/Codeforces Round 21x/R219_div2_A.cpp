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
  int k;
  cin >> k;
  map<int, int> m;
  char x;
  for (int i = 0; i < 16; i++) {
    cin >> x;
    if (isdigit(x))
      m[x - '0']++;
  }
  for (int i = 1; i <= 9; i++) {
    if (m[i] > k * 2) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
