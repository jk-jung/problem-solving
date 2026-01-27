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
  string a, b;
  cin >> a >> b;

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  int n = 2;
  for (char x : a)
    n = max(n, x - '0' + 1);
  for (char x : b)
    n = max(n, x - '0' + 1);

  int carry = 0;
  int cnt = 0;
  for (int i = 0; i < max(a.size(), b.size()); i++) {
    cnt++;
    int aa = i < a.size() ? a[i] - '0' : 0;
    int bb = i < b.size() ? b[i] - '0' : 0;
    int t = carry + aa + bb;
    carry = t / n;
    t %= n;
  }
  if (carry)
    cnt++;
  cout << cnt << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
