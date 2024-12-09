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

int n, m;
int v[22][22];
map<string, int> idx;
map<int, string> rv;
vi cur, r;

void dfs(int x) {
    if (x == n ) {
        if (r.size() < cur.size())r = cur;
        return;
    }

    bool can = true;
    for (int y: cur)if (v[x][y])can = false;
    if (can) {
        cur.pb(x);
        dfs(x + 1);
        cur.pop_back();
    }
    dfs(x + 1);
}

void solve() {
    cin >> n >> m;
    vector<string> t(n);
    for (auto &x: t) cin >> x;
    sort(t.begin(), t.end());
    for(auto &x:t) {
        int sz = idx.size();
        idx[x] = sz;
        rv[sz] = x;
    }

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        int x = idx[a];
        int y = idx[b];
        v[x][y] = v[y][x] = 1;
    }
    dfs(0);

    cout << r.size() << endl;
    for(int x:r)cout << rv[x]<< endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
