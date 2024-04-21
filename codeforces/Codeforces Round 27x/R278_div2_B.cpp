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

void check(map<int, int> a, map<int, int> b) {
	for (auto [x, y] : a) {
		if (b[x] < y) return;
	}
	cout << "YES\n";
	for (auto [x, y] : b) {
        y -= a[x];
		while (y--) cout << x << '\n';
	}
    exit(0);
}
void solve() {
	// a + b + c + d == 4x
	// b + c == 2x
	// d - a == x

	// -a + b + c + d == 3x

	// set a
	// x == 2a
	// d = x + a
	// b + c == 2x

	int n;
	cin >> n;
	deque<int> v(n);
	map<int, int> ck;
	for (int& x : v) cin >> x, ck[x]++;

	for (int a = 1; a <= 1000; a++) {
		int x = 2 * a;
		int d = x + a;
		for (int b = a;; b++) {
			int c = 2 * x - b;
			if (c < b) break;
			map<int, int> c2;
			c2[a]++;
			c2[b]++;
			c2[c]++;
			c2[d]++;
			check(ck, c2);
		}
	}
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
}
