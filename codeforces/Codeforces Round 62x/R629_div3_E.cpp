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


int n, m;
vi v[200005];
int S[200005];
int E[200005], CK;
int a[200005];
int p[200005];
int dep[200005];

void dfs(int x, int y = 1, int d = 0) {
    S[x] = CK++;
    p[x] = y;
    dep[x] = d;
    for (int z: v[x])if (z != y)dfs(z, x, d + 1);
    E[x] = CK;
}

bool sf(int x, int y) {
    return dep[x] < dep[y];
}

void solve() {
    cin >> n >> m;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    dfs(1);

    while (m--) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> a[i], a[i] = p[a[i]];
        }

        sort(a, a + k, sf);

        bool r = true;
        for (int i = 1; i < k; i++) {
            int x = a[i - 1], y = a[i];
            if (S[x] <= S[y] && E[y] <= E[x]);
            else r = false;
        }
        cout << (r ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
