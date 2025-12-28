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
  string a, b, c;
  cin >> a >> b >> c;

  if (a[1] == '>')
    swap(a[0], a[2]);
  if (b[1] == '>')
    swap(b[0], b[2]);
  if (c[1] == '>')
    swap(c[0], c[2]);

  if (a[0] != b[0] && a[0] != c[0] && b[0] != c[0]) {
    cout << "Impossible";
    return;
  }

  if (a[0] == b[0]) {
    cout << a[0] << c[0] << c[2] << endl;

  } else if (a[0] == c[0]) {
    cout << a[0] << b[0] << b[2] << endl;
  } else if (b[0] == c[0]) {
    cout << b[0] << a[0] << a[2] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
