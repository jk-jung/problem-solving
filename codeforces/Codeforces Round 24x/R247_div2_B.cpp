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

int g[55][55];
void solve() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) cin >> g[i][j];

	vi v;
	for (int i = 0; i < 5; i++) v.pb(i);
	int r = 0;
	do {
		int t = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = i; j + 1 < 5; j += 2) {
				int x = v[j];
				int y = v[j + 1];
				t += g[x][y] + g[y][x];
			}
		}
		r = max(r, t);
	} while (next_permutation(v.begin(), v.end()));
	cout << r << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
}
