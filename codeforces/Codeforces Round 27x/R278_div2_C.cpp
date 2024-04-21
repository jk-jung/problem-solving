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

int h1, a1, d1;
int h2, a2, d2;
int h, a, d;

int calc(int x, int y) {
	int aa = a1 + x;
	int dd = d1 + y;

	int t1 = max(0, a2 - dd);
	int t2 = max(0, aa - d2);

	if (t2 == 0) return 1 << 30;
	if (t1 == 0) return 0;

	int cnt1 = (h1 + t1 - 1) / t1;
	int cnt2 = (h2 + t2 - 1) / t2;

	if (cnt1 > cnt2) return 0;
	return (cnt2 * t1 - h1 + 1) * h;
}
void solve() {
	cin >> h1 >> a1 >> d1;
	cin >> h2 >> a2 >> d2;
	cin >> h >> a >> d;

	int r = 1 << 30;
	for (int i = 0; i <= 200; i++) {
		for (int j = 0; j <= 200; j++) {
			int cost = i * a + j * d + calc(i, j);
			r = min(r, cost);
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
