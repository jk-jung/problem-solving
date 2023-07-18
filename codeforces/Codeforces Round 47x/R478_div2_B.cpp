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

ll f(vector<ll> v, int x) {
    ll t = v[x];
    v[x] = 0;
    for (int i = 0; i < 14; i++) {
        v[(x + i + 1) % 14] += t / 14 + (t % 14 > i);
    }
    ll r = 0;
    for (ll y: v)if (y % 2 == 0)r += y;
    return r;
}

void solve() {
    vector<ll> v(14);
    for (ll &x: v)cin >> x;
    ll r = 0;
    for (int i = 0; i < 14; i++)r = max(r, f(v, i));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
