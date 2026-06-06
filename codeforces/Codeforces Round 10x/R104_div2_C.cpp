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

int d[1000005];
void solve() {
  string a, b;
  cin >> a >> b;

  int x = 0, y = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      if (a[i] == '4')
        x++;
      else
        y++;
    }
  }

  cout << max(x, y) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
