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
  string s;
  cin >> s;
  int n = s.size();
  if (n % 2) {
    int m = n / 2 + 1;
    cout << string(m, '4') << string(m, '7') << endl;
  } else {
    int m = n / 2;
    string a = string(m, '4') + string(m, '7');
    string b = string(m, '7') + string(m, '4');
    if (a >= s)
      cout << a << endl;
    else if (a < s && s <= b) {
      do {
        if (a >= s) {
          cout << a << endl;
          return;
        }
      } while (next_permutation(a.begin(), a.end()));
    } else {
      m++;
      cout << string(m, '4') << string(m, '7') << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
