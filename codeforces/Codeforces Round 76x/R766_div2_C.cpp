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


int n;
vi v[100005];
int r[100005];
map<pi, int> ck;

void dfs(int x, int y = 0, int c = 2) {
    if (y)r[ck[{x, y}]] = c;
    for (int z: v[x]) {
        if (z == y)continue;
        dfs(z, x, 5 - c);
        c = 5 - c;
    }
}

void solve() {
    cin >> n;
    int m = 0;
    for (int i = 0, s, e; i < n - 1; i++) {
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
        m = max(m, (int) v[s].size());
        m = max(m, (int) v[e].size());
        ck[{s, e}] = i;
        ck[{e, s}] = i;
    }

    if (m >= 3) {
        cout << -1 << endl;
    } else {
        dfs(1);
        for (int i = 0; i < n - 1; i++)cout << r[i] << " ";
        cout << endl;
    }

    for (int i = 0; i <= n; i++)v[i].clear();
    ck.clear();
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
// 1 3 4
// 2