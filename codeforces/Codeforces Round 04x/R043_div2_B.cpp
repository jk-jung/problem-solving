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

string ss[5] = {"S", "M", "L", "XL", "XXL"};

void solve() {
  int n;
  vi v(5);
  for (int &x : v)
    cin >> x;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;

    int x = 0;
    if (s == "S")
      x = 0;
    else if (s == "M")
      x = 1;
    else if (s == "L")
      x = 2;
    else if (s == "XL")
      x = 3;
    else if (s == "XXL")
      x = 4;

    for (int i = 0; i < 5; i++) {
      if (x + i < 5 && v[x + i] > 0) {
        v[x + i]--;
        cout << ss[x + i] << endl;
        break;
      } else if (x - i >= 0 && v[x - i] > 0) {
        v[x - i]--;
        cout << ss[x - i] << endl;
        break;
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
