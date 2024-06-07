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

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> v(n), q(n);
    for (ll &x: v)cin >> x;
    ll s = 0;
    while (m--) {
        ll op, a, b;
        cin >> op >> a;
        if (op == 1) {
            a--;
            cin >> b;
            q[a] = -s;
            v[a] = b;
        } else if (op == 2) {
            s += a;
        } else {
            a--;
            cout << v[a] + s + q[a] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
