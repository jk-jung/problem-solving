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

int n;
string s;

int check(int a, int b, char k) {
  int r = 0;
  for (int i = a; i <= b; i++)
    if (s[i] != k)
      r++;
  return r;
}

void solve() {
  cin >> n >> s;

  int H = 0, T = 0;
  for (char x : s)
    if (x == 'H')
      H++;
    else
      T++;

  if (H == 0 || T == 0) {
    cout << 0 << endl;
    return;
  }
  int r = 1 << 30;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int len = j - i + 1;
      if (len == H)
        r = min(r, check(i, j, 'H'));
      if (len == T)
        r = min(r, check(i, j, 'T'));
    }
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
