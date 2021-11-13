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

vi v[200005];
vi t[2];
int used[200005];
int r[200005];
int n;

void dfs(int x, int y, int k) {
    t[k].pb(x);
    for (int z: v[x]) {
        if (z != y) dfs(z, x, k ^ 1);
    }
}

void solve() {
    cin >> n;
    for (int i = 1, s, e; i < n; i++) {
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    dfs(1, 0, 0);
    if (t[0].size() > t[1].size())swap(t[0], t[1]);

    int m = t[0].size();
    for (int i = 0; i < 20; i++) {
        if (m >> i & 1) {
            for (int k = 0; k < (1 << i); k++) {
                int kk = (1 << i) + k;
                used[kk] = 1;
                r[t[0].back()] = kk;
                t[0].pop_back();
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] == 0) {
            r[t[1].back()] = i;
            t[1].pop_back();
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << r[i] << " ";
    }
    cout << '\n';

    for (int i = 1; i <= n; i++)v[i].clear(), used[i] = 0;
    t[0].clear();
    t[1].clear();
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
