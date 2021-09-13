#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

int n;
vi v[200005];
vi t;

pair<bool, bool> go(int x, int y) {
    int child = 0, leaf = 0;
    for (int z: v[x]) {
        if (z == y)continue;

        auto[cut, has_child] = go(z, x);

        if (!cut) {
            child++;
            if (has_child)leaf++;
        }

    }
    bool cc = false;
    if (leaf >= 1)
        t.pb(leaf), cc = true;

    return {cc, child == 0};
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    go(1, 0);

    int r = 0;
    for (int i = 0; i < t.size(); i++)r += t[i];
    cout << r - (int) t.size() + 1 << '\n';

    t.clear();
    for (int i = 0; i <= n; i++)v[i].clear();
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
