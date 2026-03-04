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

int L[1000005];
int R[1000005];
void solve() {
  string a, b;
  cin >> a >> b;

  for (int i = 0; i < a.size(); i++) {
    if (i < b.size() && a[i] == b[i])
      L[i] = i + 1;
    else
      break;
  }

  for (int i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--) {
    if (a[i] == b[j]) {
      R[i] = R[i + 1] + 1;
    } else
      break;
  }

  vi v;
  for (int i = 0; i < a.size(); i++) {
    int l = i == 0 ? 0 : L[i - 1];
    int r = R[i + 1];
    if (l + r == b.size()) {
      v.pb(i + 1);
    }
  }
  cout << v.size() << endl;
  for (int x : v)
    cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
