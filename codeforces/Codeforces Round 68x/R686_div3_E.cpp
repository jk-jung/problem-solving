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
vi v[200005];
int p[200005];
bool vis[200005];
bool cy[200005];

bool find_cycle(int x, int y = -1) {
    p[x] = y;
    vis[x] = true;
    for (int z: v[x]) {
        if (z == y)continue;
        if(vis[z]) {
            int t = x;
            cy[z] = true;
            while(t != z) {
                cy[t] = true;
                t = p[t];
            }
            return true;
        }else if(find_cycle(z, x))
            return true;
    }
    return false;
}

int dfs(int x, int y = -1) {
    int r = 1;
    for (int z: v[x]) {
        if(z == y || cy[z])continue;
        r += dfs(z, x);
    }
    return r;
}

void solve() {
    cin >> n;
    for (int i = 0, s, e; i < n; i++) {
        cin >> s >> e;
        v[s].pb(e), v[e].pb(s);
    }

    find_cycle(1);
    ll m = 0, r, tot = n;
    for (int i = 1; i <= n; i++)if (cy[i])m++;
    r = m * m - m;

    for (int i = 1; i <= n; i++) {
        if (cy[i]) {
            ll cnt = dfs(i) - 1;
            r += cnt * (2 * m - 1);
            r += cnt * (cnt - 1) / 2;
            tot -= cnt;
            r += 2 * cnt * (tot - m);
        }
    }

    cout << r << endl;
    for (int i = 1; i <= n; i++) {
        v[i].clear();
        vis[i] = false;
        cy[i] = false;
    }
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
