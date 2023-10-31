#include <cstring>
#include <cstdio>
#include <cmath>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vi r(n);
    vector<vi> v(n, vi(m));
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> v[i][j];
    vector<pi> t;
    t.pb(mp(0, 0));
    for (int j = 0; j < m; j++) {
        pi x = mp(0, 0);
        for (int i = 1; i < n; i++) {
            if (v[i - 1][j] <= v[i][j])x.S = i;
            else x = mp(i, i);
            t.pb(x);
        }
    }
    sort(t.begin(), t.end());
    priority_queue<int> q;
    for (int i = 0, p = 0; i < n; i++) {
        while (p < t.size() && t[p].F == i) {
            q.emplace(t[p].S);
            p++;
        }
        r[i] = i;
        if (!q.empty())r[i] = q.top();
        while (!q.empty() && q.top() == i)q.pop();
    }


    int k;
    cin >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << (r[x] >= y ? "Yes" : "No") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
