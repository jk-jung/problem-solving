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


void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> v(n + 1);
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        v[a] += c;
        v[b] -= c;
    }
    queue<int> x, y;
    for (int i = 1; i <= n; i++) {
        if (v[i] > 0)x.push(i);
        if (v[i] < 0)y.push(i), v[i] = -v[i];
    }
    vector<tuple<int, int, ll>> r;
    while (!x.empty()) {
        int a = x.front();
        int b = y.front();

        ll t = min(v[a], v[b]);
        v[a] -= t;
        v[b] -= t;
        r.pb({a, b, t});

        if (v[a] == 0)x.pop();
        if (v[b] == 0)y.pop();
    }

    cout << r.size() << endl;
    for (auto [a, b, c]: r) {
        cout << a << " " << b << " " << c << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
