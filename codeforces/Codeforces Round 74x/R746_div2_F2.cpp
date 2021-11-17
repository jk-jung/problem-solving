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

char a[505][505];
int d[505][505];
int n, m;

int calc() {
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] == 'B') d[i][j]++;
            if (a[i + 1][j] == 'B') d[i][j]++;
            if (a[i][j + 1] == 'B') d[i][j]++;
            if (a[i + 1][j + 1] == 'B') d[i][j]++;
            d[i][j] %= 2;
            r += d[i][j];
        }
    }
    return r;
}

class BipartiteGraph {
public:
    int n, m, vis_cnt;
    vi L, R, vis;
    vector<vi> v;


    BipartiteGraph(int _n, int _m) {
        init(_n, _m);
    }

    void init(int _n, int _m) {
        n = _n, m = _m, vis_cnt = 0;
        L.clear(), L.resize(n, -1);
        R.clear(), R.resize(m, -1);
        vis.clear(), vis.resize(n, -1);
        v.clear(), v.resize(n);
    }

    void add(int s, int e) { v[s].pb(e); }

    int compute_max_matching() {
        int r = 0;
        for (int i = 0; i < n; i++, vis_cnt++) {
            if (dfs(i)) r++;
        }
        return r;
    }

private:
    bool dfs(int x) {
        if (vis[x] == vis_cnt) return false;
        vis[x] = vis_cnt;

        for (int y: v[x]) {
            if (R[y] < 0 || dfs(R[y])) {
                R[y] = x, L[x] = y;
                return true;
            }
        }
        return false;
    }
};

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];
    int r = calc();

    BipartiteGraph bg(n, m);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (d[i][m - 1] == 0)continue;
            if (d[n - 1][j] == 0)continue;
            if (d[i][j] == 0)continue;
            bg.add(i, j);
        }
    }

    int mm = bg.compute_max_matching();
    if (d[n - 1][m - 1] == 1 && mm % 2) r--;
    if (d[n - 1][m - 1] == 0 && mm % 2) r++;
    cout << r - mm;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
