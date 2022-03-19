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


vi v[100005];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)v[i].clear();

    vi deg(m + 1);
    for (int i = 0, k, x; i < m; i++) {
        cin >> k;
        while (k--) {
            cin >> x;
            v[x].pb(i);
            deg[i]++;
        }
    }

    int limit = (m + 1) / 2;
    int idx = -1, rd0 = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() < limit)continue;

        int d0 = 0;
        for (int x: v[i]) if (deg[x] == 1)d0++;

        if (idx == -1 || rd0 < d0)idx = i, rd0 = d0;
    }

    vi r(m);
    if (idx > 0) {
        for (int x: v[idx]) {
            if (deg[x] == 1 && limit) {
                r[x] = idx;
                limit--;
            }
        }
        for (int x: v[idx]) {
            if (deg[x] != 1 && limit) {
                r[x] = idx;
                limit--;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i == idx)continue;
        for (int x: v[i]) {
            if (r[x] == 0) r[x] = i;
        }
    }
    for (int i = 0; i < m; i++)
        if (!r[i]) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
    for (int x: r)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
