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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x: v) cin >> x;
    int r = 0;
    for (int y0 = 0; y0 < n; y0++) {
        for (int y1 = y0; y1 < n; y1++) {
            for (int x0 = 0; x0 < m; x0++) {
                for (int x1 = x0; x1 < m; x1++) {
                    int ok = true;
                    for (int i = y0; i <= y1; i++) {
                        for (int j = x0; j <= x1; j++) {
                            if (v[i][j] == '1')ok = false;
                        }
                    }
                    if (ok)r = max(r, (x1 - x0 + 1) + (y1 - y0 + 1));
                }
            }
        }
    }
    cout << r * 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
