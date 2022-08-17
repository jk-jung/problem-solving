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
    int n, m;
    cin >> n >> m;
    vi v(m), r(m);

    ll s = 0;
    for (int &x: v)cin >> x, s += x;
    for (int i = 0, pos = 1; i < m; i++) {
        if (pos + s - 1 < n || pos + v[i] - 1 > n) {
            cout << -1 << '\n';
            return;
        }
        s -= v[i];
        r[i] = pos;
        ll need = n - s + 1;

        pos = (int)min(max((ll)pos + 1, need), (ll)pos + v[i]);
    }

    for (int x: r)cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}
