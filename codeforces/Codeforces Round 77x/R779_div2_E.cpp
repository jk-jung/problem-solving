/*
// A better reference

int pp = -inf, pn = -inf, np = -inf, nn = -inf;
for (int i = n * n - 1; i >= 0; i--) {
    auto [x, y] = pos[i];
    if (pp > x + y + k || pn > x - y + k || np > -x + y + k || nn > -x - y + k) {
        continue;
    }
    pp = std::max(pp, x + y);
    pn = std::max(pn, x - y);
    np = std::max(np, -x + y);
    nn = std::max(nn, -x - y);
}
 */

#include <string.h>
#include <stdio.h>
#include <math.h>
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

int n, k;
char r[2005][2005];
vi st(4);

void update(int y, int x) {
    int v1 = y + x;
    int v2 = y - x;
    st[0] = max(st[0], v1);
    st[1] = min(st[1], v1);
    st[2] = max(st[2], v2);
    st[3] = min(st[3], v2);
}

bool can(int y, int x) {
    int v1 = y + x;
    int v2 = y - x;
    int r1 = max(ab(st[0] - v1), ab(st[1] - v1));
    int r2 = max(ab(st[2] - v2), ab(st[3] - v2));
    return max(r1, r2) <= k;
}

void solve() {
    st[0] = -(1 << 30);
    st[2] = -(1 << 30);
    st[1] = 1 << 30;
    st[3] = 1 << 30;
    cin >> n >> k;
    vector<pair<int, pi>> v(n * n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int p = i * n + j;
            cin >> v[p].F;
            v[p].S = {i, j};
        }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        auto[y, x] = v[i].S;
        if (i == 0 || can(y, x)) {
            update(y, x);
            r[y][x] = 'M';
        } else {
            r[y][x] = 'G';
        }
    }

    for (int i = 0; i < n; i++)cout << r[i] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
