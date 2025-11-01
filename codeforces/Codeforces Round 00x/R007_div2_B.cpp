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
#include <valarray>
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

int a[1005];
bool b[1005];
int idx = 0;
void solve() {
  int n, t;
  cin >> n >> t;
  while (n--) {
    string s;
    cin >> s;
    int x;
    if (s[0] == 'a') {
      cin >> x;
      int cnt = 0;
      for (int i = 0; i < t; i++) {
        if (a[i] == 0) {
          if (++cnt == x) {
            idx++;
            for (int j = i - x + 1; j <= i; j++) {
              a[j] = idx;
              b[j] = true;
            }
            break;
          }
        } else
          cnt = 0;
      }
      if (cnt == x) {
        cout << idx << endl;
      } else
        cout << "NULL" << endl;
    } else if (s[0] == 'e') {
      cin >> x;
      bool ok = false;
      for (int i = 0; i < t; i++) {
        if (a[i] == x && b[i]) {
          a[i] = 0;
          b[i] = false;
          ok = true;
        }
      }
      if (!ok)
        cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
    } else {
      vi k;
      for (int i = 0; i < t; i++)
        if (a[i])
          k.pb(a[i]);
      memset(a, 0, sizeof(a));
      memset(b, false, sizeof(b));
      for (int i = 0; i < k.size(); i++) {
        a[i] = k[i];
        b[i] = true;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
