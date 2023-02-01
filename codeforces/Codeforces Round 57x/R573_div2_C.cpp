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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(m);
    for (ll &x: v)cin >> x;
    ll r = 0, c = 1, t = 0, last = -10000;

    for (int i = 0; i < m; i++) {
        if ((v[i] - c) / k == last) {
            t++;
            continue;
        } else {
            r++;
            c += t;
            last = (v[i] - c) / k;
            t = 1;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
