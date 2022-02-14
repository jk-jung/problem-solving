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
vector<pi> v[400005];
int vis[400005];
vector<pi> r;

pair<ll, ll> to_tan(ll a, ll b) {
    ll g = gcd(a, b);
    return {a / g, b / g};
}

int dfs(int x) {
    vis[x] = 1;
    int remain = 0, last = 0;
    for (auto[y, i]: v[x]) {
        if (vis[y] == 1)continue;

        remain = i;
        if (!vis[y]) {
            int j = dfs(y);
            if (j) {
                r.pb({i, j});
                remain = 0;
            }
        }
        if (remain && last) {
            r.pb({remain, last});
            remain = last = 0;
        }
        if (remain) last = remain;
    }
    vis[x] = 2;
    return last;
}


void solve() {
    map<pair<ll, ll>, int> ck;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        auto t1 = to_tan((a + b) * d, b * c);
        auto t2 = to_tan(a * d, b * (c + d));

        if (!ck.count(t1)) ck[t1] = cnt++;
        if (!ck.count(t2)) ck[t2] = cnt++;
        int k1 = ck[t1];
        int k2 = ck[t2];

        v[k1].pb({k2, i + 1});
        v[k2].pb({k1, i + 1});
    }

    for (int i = 0; i < cnt; i++) if (!vis[i])dfs(i);

    cout << r.size() << endl;
    for (auto[x, y]: r) cout << x << " " << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
