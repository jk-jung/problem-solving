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
    vi v(n);
    for (int &x: v)cin >> x;
    vector<pi> r;
    int cost = 0;

    if (m < n || n == 2) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        r.pb({i + 1, j + 1});
        cost += v[i] + v[j];
    }
    sort(v.begin(), v.end());
    for (int i = n; i < m; i++)cost += v[0] + v[1];

    cout << cost << endl;
    for (auto [x, y]: r)cout << x << " " << y << endl;
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
