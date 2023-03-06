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

void solve() {
    int n, q;
    cin >> n >> q;

    vi c(n);
    vector<vi> st(n);
    vector<pi> v(q);

    for (auto &[x, y]: v) cin >> x >> y, x--, y--;
    int idx = 0;
    for (auto [x, y]: v) {
        for (int i = x; i <= y; i++)c[i]++, st[i].pb(idx);
        idx++;
    }
    idx = 0;
    int r = 0;
    for (auto [x, y]: v) {
        for (int i = x; i <= y; i++)c[i]--;
        vi t(q);
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (c[i])tot++;
            if (c[i] == 1)
                for (auto it: st[i]) t[it]++;
        }
        for (int i = 0; i < q; i++)if (i != idx)r = max(r, tot - t[i]);
        for (int i = x; i <= y; i++)c[i]++;
        idx++;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
