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


map<ll, ll> cost;

void add(ll a, ll b, ll w) {
    while (a != b) {
        cost[a] += w;
        a /= 2;
    }
}

ll calc(ll a, ll b) {
    ll r = 0;
    while (a != b) {
        if (cost.count(a))r += cost[a];
        a /= 2;
    }
    return r;
}

ll common_root(ll a, ll b) {
    while (a != b) {
        if (a > b)a /= 2;
        if (a < b) b /= 2;
    }
    return a;
}

void solve() {
    ll q;
    cin >> q;
    while (q--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll a, b, w;
            cin >> a >> b >> w;
            ll r = common_root(a, b);
            add(a, r, w);
            add(b, r, w);
        } else {
            ll a, b;
            cin >> a >> b;
            ll r = common_root(a, b);
            cout << calc(a, r) + calc(b, r) << endl;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
