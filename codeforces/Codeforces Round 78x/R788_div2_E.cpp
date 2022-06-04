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


vector<pi> v[1 << 18];
int r[1 << 18], r2[1 << 18];
int n, val;

void dfs(int x, int y = -1, int st = 0) {
    for (auto [z, i]: v[x]) {
        if (z != y) {
            val++;
            r2[i] = st ^ val ^ n;
            r[z] = st ^ val;
            dfs(z, x, st ^ n);
        }
    }
}

void solve() {
    int p;
    cin >> p;
    n = 1 << p;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb({y, i});
        v[y].pb({x, i});
    }

    r[1] = n;
    val = 0;
    dfs(1);

    cout << 1 << endl;
    for (int i = 1; i <= n; i++)cout << r[i] << " ";
    cout << endl;
    for (int i = 1; i < n; i++)cout << r2[i] << " ";
    cout << endl;

    for (int i = 1; i <= n; i++)v[i].clear();
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
