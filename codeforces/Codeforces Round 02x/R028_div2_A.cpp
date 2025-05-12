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
vector<pi> v;
vi t;


int d(int i, int j) {
    return ab(v[i].F - v[j].F) + ab(v[i].S - v[j].S);
}

void check(int s) {
    vi used(m);
    vi r(n, -1);

    for (int i = s; i < n; i += 2) {
        int j = (i - 1 + n) % n;
        int k = (i + 1) % n;
        int dis = d(i, j) + d(i, k);
        bool ok = false;
        for (int x = 0; x < m; x++) {
            if (used[x])continue;
            if (dis == t[x]) {
                used[x] = 1;
                r[i] = x + 1;
                ok = true;
                break;
            }
        }
        if (!ok)return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << r[i] << " ";
    }
    exit(0);
}

void solve() {
    cin >> n >> m;
    v.resize(n);
    t.resize(m);

    for (auto &[x, y]: v)cin >> x >> y;
    for (int &x: t)cin >> x;

    check(0);
    check(1);
    cout << "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
