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

pair<string, string> parse(string &s, char sep) {
  vector<string> v(2);
  int idx = 0;
  for (char x : s) {
    if (x == sep) {
      idx++;
      continue;
    }
    v[idx] += x;
  }
  return {v[0], v[1]};
}

struct Data {
  int a, b, c;
  string name;
};
bool cmp(Data &a, Data &b) {
  if (a.a != b.a)
    return a.a > b.a;
  if (a.b != b.b)
    return a.b > b.b;
  return a.c > b.c;
}
void solve() {
  int n;
  cin >> n;
  vector<Data> v(n);
  for (auto &x : v)
    cin >> x.name;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string a, b;
      cin >> a >> b;
      auto [t1, t2] = parse(a, '-');
      auto [n1, n2] = parse(b, ':');
      int i1, i2;
      for (int k = 0; k < n; k++) {
        if (t1 == v[k].name)
          i1 = k;
        if (t2 == v[k].name)
          i2 = k;
      }
      int x = stoi(n1);
      int y = stoi(n2);
      v[i1].b += x - y;
      v[i2].b += y - x;
      v[i1].c += x;
      v[i2].c += y;
      if (x > y)
        v[i1].a += 3;
      else if (x < y)
        v[i2].a += 3;
      else {
        v[i1].a += 1;
        v[i2].a += 1;
      }
    }
  }
  sort(v.begin(), v.end(), cmp);
  vector<string> r;
  for (int i = 0; i < n / 2; i++) {
    r.pb(v[i].name);
  }
  sort(r.begin(), r.end());
  for (auto x : r)
    cout << x << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
