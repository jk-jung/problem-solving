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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    vi c(n);
    for (auto &x: v)cin >> x;
    for (int &x: c)cin >> x;
    map<string, int> g;
    for (int i = 0; i < n; i++)g[v[i]] = c[i];
    for (int i = 0, t; i < m; i++) {
        cin >> t;
        vi q(t);
        int cc = 1 << 30;
        for (int &x: q)cin >> x, cc = min(cc, c[x - 1]);
        for (int x: q)g[v[x - 1]] = cc;
    }
    ll r = 0;
    while (k--) {
        string s;
        cin >> s;
        r += g[s];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
