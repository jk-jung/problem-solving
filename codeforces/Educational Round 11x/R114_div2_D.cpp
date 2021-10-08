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


int n, m;
vi v[10];
map<vi, int> ck;
map<vi, int> vis;

void solve() {
    cin >> n;
    vi s(n);
    ll ss = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v[i].resize(t);
        for (int j = 0; j < t; j++)cin >> v[i][j];
        s[i] = t - 1;
        ss += v[i].back();
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        vi t(n);
        for (int j = 0; j < n; j++) cin >> t[j], t[j] --;
        ck[t] = 1;
    }

    priority_queue<pair<ll, vi>> pq;
    pq.push({ss, s});
    vis[s] = 1;

    while (!pq.empty()) {
        auto[x_sum, x] = pq.top();
        pq.pop();
        if (ck.count(x) == 0) {
            for (int i = 0; i < n; i++)cout << x[i] + 1 << " ";
            return;
        }

        for (int i = 0; i < n; i++) {
            if (x[i] == 0)continue;

            ll y_sum = x_sum - v[i][x[i]] + v[i][x[i] -1];
            x[i] --;
            if(vis.count(x) == 0) {
                pq.push({y_sum, x});
                vis[x] = 1;
            }
            x[i] ++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
