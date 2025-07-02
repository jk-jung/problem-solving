#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


vector<pi> edges[100005];
int from[155555];

void print(int x) {
    if (x != 1)print(from[x]);
    cout << x << " ";
}

void solve() {
    int n, m;
    cin >> n >> m;


    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        edges[x].pb(mp(y, z));
        edges[y].pb(mp(x, z));
    }
    vector<ll> d(n + 1, 1ll << 60);
    d[1] = 0;
    priority_queue<pair<ll, int> > q;
    q.push(mp(0, 1));
    while (!q.empty()) {
        auto [dis, x] = q.top();
        q.pop();
        dis = -dis;
        if (d[x] < dis) continue;

        for (auto [y, w]: edges[x]) {
            if (d[x] + w < d[y]) {
                d[y] = d[x] + w;
                from[y] = x;
                q.push(mp(-d[y], y));
            }
        }
    }
    if (d[n] == (1ll << 60))cout << -1;
    else print(n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
