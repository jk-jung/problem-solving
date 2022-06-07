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

vi v1[200005];
vector<pi> ee, ee2;
vi nodes;
int ord[200005], N;
int deg[200005];
int n, m;

bool tsort() {
    N = 0;
    queue<int> q;

    for (int x: nodes) if (deg[x] == 0)q.push(x);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ord[x] = ++N;

        for (int y: v1[x])if (--deg[y] == 0)q.push(y);
    }

    return N == nodes.size();
}

void solve() {
    cin >> n >> m;
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        if (x) {
            v1[y].pb(z);
            deg[z]++;
            nodes.pb(y);
            nodes.pb(z);
            ee2.pb({y, z});
        } else {
            ee.pb({y, z});
        }
    }
    sort(nodes.begin(), nodes.end());
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

    if (!tsort()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto [x, y]: ee) {
            int a = ord[x];
            int b = ord[y];
            if (a == 0 && b == 0) {
                if(x < y)swap(x, y);
            } else if (a == 0) {
            } else if (b == 0) {
                swap(x, y);
            } else {
                if(a > b) swap(x, y);
            }
            cout << x << " " << y << '\n';
        }
        for (auto [x, y]: ee2) cout << x << " " << y << '\n';
    }

    nodes.clear();
    ee.clear();
    ee2.clear();
    for (int i = 0; i <= n; i++) {
        v1[i].clear();
        ord[i] = 0;
        deg[i] = 0;
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
