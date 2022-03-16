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

vector<pi> edge[100005];
ll d[100005];
int vis[100005];

void solve() {
    int n;
    cin >> n;

    ll r = 0;
    vector<pi> v(n);
    for (auto&[x, y]: v)cin >> x >> y, r += y;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (i)edge[i].pb({i - 1, 0});

        int c = v[i].F + v[i].S;
        int j = lower_bound(v.begin(), v.end(), mp(c + 1, 0)) - v.begin();
        if (i < j && j < n) edge[i].pb({j, v[j].F - c});
        if (j - 1 > i) edge[i].pb({j - 1, 0});
    }

    memset(d, 63, sizeof(d));
    d[0] = 0;
    priority_queue<pair<ll, int>> q;
    q.push({0ll, 0});

    while (!q.empty()) {
        auto[cost, x] = q.top();
        cost = -cost;
        q.pop();

        if (vis[x]) continue;
        vis[x] = 1;

        if (x == n - 1) {
            r += cost;
            break;
        }

        for (auto[y, c]: edge[x]) {
            if (!vis[y] && cost + c < d[y]) {
                d[y] = cost + c;
                q.push({-d[y], y});
            }
        }
    }


    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
