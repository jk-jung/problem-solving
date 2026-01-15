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

string make(vector<string> &v) {
  if (v[0].size() + v[2].size() != v[1].size() + 1)
    return "";
  if (v[3].size() + v[5].size() != v[4].size() + 1)
    return "";

  int x = v[0].size() - 1;
  int y = v[3].size() - 1;

  if (v[0][0] != v[3][0] || v[0].back() != v[4][0])
    return "";
  if (v[1][0] != v[3].back() || v[1][x] != v[4][y] || v[1].back() != v[5][0])
    return "";
  if (v[2][0] != v[4].back() || v[2].back() != v[5].back())
    return "";

  int m = v[1].size() - 1;
  int n = v[4].size() - 1;

  vector<string> r(n + 1, string(m + 1, '.'));
  for (int i = 0; i < v[0].size(); i++)
    r[0][i] = v[0][i];
  for (int i = 0; i < v[1].size(); i++)
    r[y][i] = v[1][i];
  for (int i = 0; i < v[2].size(); i++)
    r[n][x + i] = v[2][i];

  for (int i = 0; i < v[3].size(); i++)
    r[i][0] = v[3][i];
  for (int i = 0; i < v[4].size(); i++)
    r[i][x] = v[4][i];
  for (int i = 0; i < v[5].size(); i++)
    r[y + i][m] = v[5][i];

  string rr;
  for (auto &x : r)
    rr += x + '\n';
  return rr;
}

void solve() {
  vector<string> v(6);
  for (auto &x : v)
    cin >> x;
  sort(v.begin(), v.end());

  string r;
  do {
    string t = make(v);
    if (!t.empty())
      r = r.empty() ? t : min(r, t);

  } while (next_permutation(v.begin(), v.end()));

  if (r.empty())
    cout << "Impossible";
  else
    cout << r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
