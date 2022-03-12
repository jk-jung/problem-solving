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
map<pi, int> ck;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
pi r[200005];
vi edge[200005];
int vis[200005];

int dis(pi a, pi b) {
    return ab(a.F - b.F) + ab(a.S - b.S);
}

void solve() {
    cin >> n;
    vector<pi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F >> v[i].S;
        ck[v[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 4; k++) {
            pi p = {v[i].F + dx[k], v[i].S + dy[k]};

            if (ck.count(p)) {
                int j = ck[p];
                edge[i].pb(j);
            } else {
                r[i] = p;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (edge[i].size() <= 3) {
            q.push(i);
            vis[i] = 1;
        }
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        if (edge[i].size() == 4) {
            pi x = v[i], t = {1 << 30, 1 << 30};
            for (int j: edge[i]) {
                pi y = r[j];
                if (dis(x, y) < dis(x, t)) t = y;
            }
            r[i] = t;
        }

        for (int j: edge[i]) {
            if (vis[j] == 0 && edge[j].size() == 4) {
                vis[j] = 1;
                q.push(j);
            }
        }
    }

    for (int i = 0; i < n; i++)cout << r[i].F << " " << r[i].S << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
