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
    int n, q;
    cin >> n >> q;
    vector<ll> v(n), ck(n);
    ll r = 0;
    for (ll &x: v)cin >> x, r += x;

    ll idx = 0, last;
    while (q--) {
        ll op, x;
        cin >> op >> x;
        if (op == 1) {
            ll y;
            cin >> y;
            x--;
            if (ck[x] == idx) {
                r += y - v[x];
            } else {
                r += y - last;
            }
            ck[x] = idx;
            v[x] = y;
        } else {
            r = n * x;
            idx++;
            last = x;
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
