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

ll f(ll x, ll t) {
    return x / 3 + (x % 3 >= t);
}

void solve() {
    ll n, s, e;
    cin >> n >> s >> e;
    vector<ll> c(3), r(3);
    s--;
    c[0] = f(e, 3) - f(s, 3);
    c[1] = f(e, 1) - f(s, 1);
    c[2] = f(e, 2) - f(s, 2);

    r[0] = 1;
    for (int i = 1; i <= n; i++) {
        vector<ll> nt(3);
        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 3; j++) {
                nt[(k + j) % 3] += r[k] * c[j];
            }
        }
        for (int k = 0; k < 3; k++)nt[k] %= 1000000007;
        r = nt;
    }
    cout << r[0] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
