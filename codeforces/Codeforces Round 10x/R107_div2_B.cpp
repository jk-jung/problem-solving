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

void print(vector<string> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
    if (i != a.size() - 1)
      cout << ", ";
  }
  cout << "." << endl;
}

void solve() {
  int n;
  cin >> n;

  vector<string> a, b, c;
  int A = 0, B = 0, C = 0;

  for (int i = 0; i < n; i++) {
    int m;
    string s;
    cin >> m >> s;
    int AA = 0, BB = 0, CC = 0;
    while (m--) {
      string t;
      cin >> t;
      if (t[0] == t[1] && t[1] == t[3] && t[3] == t[4] && t[4] == t[6] &&
          t[6] == t[7]) {
        AA++;
      } else if (t[0] > t[1] && t[1] > t[3] && t[3] > t[4] && t[4] > t[6] &&
                 t[6] > t[7]) {
        BB++;
      } else {
        CC++;
      }
    }
    if (AA >= A) {
      if (AA > A)
        a.clear();
      a.pb(s);
      A = AA;
    }

    if (BB >= B) {
      if (BB > B)
        b.clear();
      b.pb(s);
      B = BB;
    }

    if (CC >= C) {
      if (CC > C)
        c.clear();
      c.pb(s);
      C = CC;
    }
  }

  cout << "If you want to call a taxi, you should call: ";
  print(a);

  cout << "If you want to order a pizza, you should call: ";
  print(b);

  cout
      << "If you want to go to a cafe with a wonderful girl, you should call: ";
  print(c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
