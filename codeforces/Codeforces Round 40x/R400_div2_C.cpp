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


ll calc(vi &v, ll t) {
    map<ll, int> ck;
    ck[0] = 1;
    ll s = 0, r = 0;
    for (int x: v) {
        s += x;
        ll y = s - t;
        if (ck.count(y))r += ck[y];
        ck[s]++;
    }
    return r;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;

    ll r = 0;
    for (ll t = 1; t < 1e14 + 1; t *= k) {
        r += calc(v, t);
        if (k == 1)break;
        if (k == -1 && t == -1)break;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
