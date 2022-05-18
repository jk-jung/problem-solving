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
ll S;
vector<tuple<int, int, int>> v[100005];
int w[100005];
int c[100005];
int cnt[100005];

int dfs(int x, int y = -1) {
    int r = 0;
    for (auto [z, a, b]: v[x]) {
        if (z == y)continue;
        w[z] = a;
        c[z] = b;
        r += dfs(z, x);
    }
    if (r == 0)r = 1;
    if(x != 1)cnt[x] = r;
    return r;
}


void calc(int k, vector<ll> &r) {
    priority_queue<tuple<ll, int, int>> q;
    for (int i = 0; i <= n; i++)
        if (c[i] == k && cnt[i] > 0) {
            ll t = (ll)(w[i] + 1) / 2 * cnt[i];
            q.push({t, w[i] / 2, cnt[i]});
        }
    r.pb(0);
    while(!q.empty()){
        auto [t, ww, cc] = q.top();
        q.pop();
        ll last = r.back();
        r.pb(last + t);

        if(ww) {
            t = (ll)(ww + 1) / 2 * cc;
            q.push({t, ww / 2, cc});
        }
    }
}

void solve() {
    cin >> n >> S;
    for (int i = 1, x, y, a, b; i < n; i++) {
        cin >> x >> y >> a;
        b = 1;
        v[x].pb({y, a, b});
        v[y].pb({x, a, b});
    }

    dfs(1);
    vector<ll> v1, v2;
    calc(1, v1);
    calc(2, v2);

    int r = 1 << 30;
    ll tot = 0;
    for (int i = 0; i <= n; i++)tot += (ll) w[i] * cnt[i];
    for (int i = 0; i < v1.size(); i++) {
        ll need = (tot - S) - v1[i];
        int idx = lower_bound(v2.begin(), v2.end(), need) - v2.begin();
        if (idx < v2.size()) r = min(r, idx * 2 + i);
    }
    cout << r << endl;

    for (int i = 0; i <= n; i++) {
        v[i].clear();
        cnt[i] = 0;
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
