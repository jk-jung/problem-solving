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

int n, c;

vector<pi> v[500005];
int last[500005];
vi r[200005];
vi used[200005];
vi rst;


void dfs(int x) {
    while (last[x] < v[x].size()) {
        auto[y, idx] = v[x][last[x]++];
        int z = x < n ? x : y;
        if (used[z][idx]) continue;

        if(z == x) {
            r[x][idx] = 1;
        }
        used[z][idx] = 1;
        dfs(y);
    }
//    rst.pb(x);
}

void solve() {
    cin >> n;
    map<int, int> ck, idx;

    for (int i = 0, m; i < n; i++) {
        cin >> m;
        r[i].resize(m);
        used[i].resize(m);

        for (int j = 0, x; j < m; j++) {
            cin >> x;
            ck[x]++;
            if (!idx.count(x)) idx[x] = c++;

            v[i].pb({n + idx[x], j});
            v[n + idx[x]].pb({i, j});
        }
    }

    for (auto[a, b]: ck) {
        if (b % 2) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < n; i++)dfs(i);

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int x: r[i])cout << (x ? 'R' : 'L');
        cout << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
