#include <cstring>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

vector<vi> v(4, vi(4));

void rotate(vi &t) {
    int dx = t[0] - t[2];
    int dy = t[1] - t[3];
    t[0] = t[2] - dy;
    t[1] = t[3] + dx;
}

bool check() {
    map<ll, ll> c;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            ll x = v[i][0] - v[j][0];
            ll y = v[i][1] - v[j][1];
            c[x * x + y * y]++;
        }
    }

    return c.size() == 2 && c.begin()->second == 4 && c.rbegin()->second == 2;
}

void process() {
    int r = 1 << 30;
    for (int i0 = 0; i0 < 4; i0++) {
        for (int i1 = 0; i1 < 4; i1++) {
            for (int i2 = 0; i2 < 4; i2++) {
                for (int i3 = 0; i3 < 4; i3++) {
                    if (check()) {
                        r = min(r, i0 + i1 + i2 + i3);
                    }
                    rotate(v[3]);
                }
                rotate(v[2]);
            }
            rotate(v[1]);
        }
        rotate(v[0]);
    }
    if (r == (1 << 30))r = -1;
    cout << r << endl;
}

void solve() {
    int n;
    cin >> n;
    while (n--) {
        for (auto &x: v) {
            for (auto &y: x)cin >> y;
        }
        process();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
