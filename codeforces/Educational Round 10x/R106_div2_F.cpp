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

const int MOD = 998244353;
int d[5005][5005];
int dep[5005];
int org[5005];
int n, K;

vi v[5005];

int dfs(int x, int y = 0) {
    for (int z: v[x])if (z != y)dep[x] = max(dep[x], dfs(z, x));
    dep[x] = min(K, dep[x] + 1);
    return dep[x];
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD)x -= MOD;
}

void sub(int &x, int y) {
    x -= y;
    if (x < 0)x += MOD;
}

void go(int x, int y = 0) {
    d[x][0] = 1;
    if (x == 2) {
        x = x;
    }
    for (int z: v[x]) {
        if (z == y) continue;

        go(z, x);
        int tot = 0, sum_a = 0, sum_b = 0, b_pos = 0, a_pos = 0;
        for (int i = 0; i <= dep[z]; i++) add(tot, d[z][i]);
        for (int i = 0; i <= dep[x]; i++)org[i] = d[x][i];

        d[x][0] = ((ll) d[x][0] * tot) % MOD;
        for (int i = 1; i <= dep[x]; i++) {
            int a = org[i];
            int b = d[z][i - 1];

            if (b_pos + 1 + i <= K) add(sum_b, d[z][b_pos++]);
            else if (b_pos + i > K) sub(sum_b, d[z][--b_pos]);

            if (a_pos + i <= K) add(sum_a, org[a_pos++]);
            else if (a_pos + i - 1 > K)sub(sum_a, org[--a_pos]);

            d[x][i] = ((ll) a * (tot + sum_b) + (ll) b * sum_a) % MOD;
        }
    }
}

void solve() {
    cin >> n >> K;
    for (int i = 1, s, e; i < n; i++) {
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }

    dfs(1);
    go(1);
    int r = 0;
    for (int i = 0; i <= n; i++)add(r, d[1][i]);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    solve();
}
