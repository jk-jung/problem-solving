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

int n, k, t;
ll d[105][2][105];
ll mod = 1000000007;

ll go(int a, int b, int s) {
	if (s > n) return 0;
	if (s == n) return b;

	ll& r = d[a][b][s];
	if (r != -1) return r;
	r = 0;
	for (int i = 1; i <= k; i++) {
		r = (r + go(a, b | (i >= t), s + i)) % mod;
	}
	return r;
}

void solve() {
	cin >> n >> k >> t;
	memset(d, -1, sizeof(d));
	cout << go(0, 0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
}
