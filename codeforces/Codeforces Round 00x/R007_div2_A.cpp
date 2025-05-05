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
    vector<string> v(8);
    vector<pi> t;
    for (auto &x: v)cin >> x;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            if (v[i][j] == 'B')t.pb({i, j});
        }
    int r = 1 << 30;
    for (int i = 0; i < (1 << 8); i++) {
        for (int j = 0; j < (1 << 8); j++) {
            bool ok = true;
            for (int y = 0; y < 8; y++) {
                for (int x = 0; x < 8; x++) {
                    if (v[y][x] == 'W') {
                        if ((i >> y & 1) || (j >> x & 1)) {

                            ok = false;
                            break;

                        }
                    } else {
                        if (!(i >> y & 1) && !(j >> x & 1)) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (!ok) break;
            }
            int cnt = 0;
            if (ok) {
                for (int k = 0; k < 8; k++) {
                    if (i >> k & 1)cnt++;
                    if (j >> k & 1)cnt++;
                }
                r = min(r, cnt);
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
