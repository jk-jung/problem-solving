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

ll a[55];
string s;
void solve() {
  for (int i = 0; i < 26; i++)
    cin >> a[i];
  cin >> s;

  int n = s.size();
  ll r = 0;
  for (int t = 0; t < 26; t++) {
    map<ll, ll> k;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      int x = s[i] - 'a';
      sum += a[x];
      if (x == t) {
        r += k[sum - a[x]];
        k[sum]++;
      }
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
