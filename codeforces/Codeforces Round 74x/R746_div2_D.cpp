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
#include<set>

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
int removed[1005];
int p[1005];
vi v[1005];

void dfs(int x, int y, vi &q) {
    p[x] = y;
    if (q.size() == m) return;
    if (!removed[x] && y) q.pb(x);
    for (int z: v[x]) if (z != y) dfs(z, x, q);
}

int query(set<int> &q) {
    cout << "? " << q.size();
    for (int x: q) cout << " " << x;
    cout << endl;

    int r;
    cin >> r;
    return r;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v[s].pb(e);
        v[e].pb(s);
    }


    int target = -1;
    m = n - 1;
    for (int _ = 0; _ < 12; _++) {
        vi q;
        dfs(1, 0, q);

        set<int> qq;
        for (int x: q) qq.insert(x), qq.insert(p[x]);
        int val = query(qq);

        if (target == -1) target = val;
        else if (target != val) {
            for (int x: q) removed[x] = 1;
        } else {
            for (int i = 1; i <= n; i++)removed[i] = 1;
            for (int x: q) removed[x] = 0;
        }

        m = 0;
        int r = -1;
        for (int i = 2; i <= n; i++)if (!removed[i])m++, r = i;

        if (m == 1) {
            cout << "! " << r << " " << p[r] << endl;
            return;
        }
        m = max(1, m / 2);
    }
    exit(1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
