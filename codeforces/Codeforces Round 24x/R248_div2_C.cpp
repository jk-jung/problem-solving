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

vi c[100005];
vector<ll> s[100005];
ll val[100005];
ll base = 0;
int n, m;

ll calc(int a, int b) {
	vi &v = c[a];
	vector<ll> &ss = s[a];
	ll r = base;

	ll idx = lower_bound(v.begin(), v.end(), b) - v.begin();

	ll t = -val[a];
	if (idx > 0) t += idx * b - ss[idx - 1];
	if (idx < ss.size()) t += ss.back() - (idx == 0 ? 0 :ss[idx - 1]) - (ss.size() - idx) * b;

	return r + t;
}
void solve() {
	cin >> n >> m;

	vi v(m);
	for (int &x : v) cin >> x;
	for (int i = 0; i < m; i++) {
		if (i > 0 && v[i] != v[i - 1]) {
			c[v[i]].pb(v[i - 1]);
			base += ab(v[i] - v[i - 1]);
		}
		if (i + 1 < m && v[i] != v[i + 1]) c[v[i]].pb(v[i + 1]);
	}

	for (int i = 1; i <= n; i++) {
		sort(c[i].begin(), c[i].end());
        if(!c[i].empty()){
            s[i].pb(c[i][0]);
            for (int j = 1; j < c[i].size(); j++) s[i].pb(s[i].back() + c[i][j]);
            for (int x : c[i]) val[i] += ab(i - x);
        }
	}

	ll r = base;
	for (int i = 0; i < m; i++) {
		if (i > 0) r = min(r, calc(v[i], v[i - 1]));
		if (i + 1 < m) r = min(r, calc(v[i], v[i + 1]));
	}
	cout << r << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
}
