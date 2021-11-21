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

int n, q;
int a[1000005];
int b[1000005];
ll rst[1000005];


int base[1000005];
int dif[1000005];

ll calc_base() {
    ll r = 0;
    b[1] = 1;
    dif[1] = 1;

    for (int i = 1; i <= n; i++) {
        base[i] = b[i] - (a[i] + base[i]);
        r += ab(base[i]);
        for (int j = i + i; j <= n; j += i) {
            base[j] += base[i];
            dif[j] -= dif[i];
        }
    }
    return r;
}

bool sf(pi &x, pi &y) {
    return x.F / x.S < y.F / y.S;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> b[i];

    ll r = calc_base();
    ll inc = 0, dec = 0;
    vector<pi> v;
    for (int i = 1; i <= n; i++) {
        if (base[i] * dif[i] < 0) {
            dec += ab(dif[i]);
            v.pb({ab(base[i]), ab(dif[i])});
        } else inc += ab(dif[i]);
    }
    sort(v.begin(), v.end(), sf);

    rst[1] = r;
    for (int i = 2, pos = 0; i <= 1000000; i++) {
        while (pos < v.size() && v[pos].F / v[pos].S + 2 <= i) {
            r -= v[pos].F % v[pos].S;
            dec -= v[pos].S;
            inc += v[pos].S;
            pos++;
        }
        r += inc - dec;
        rst[i] = r;
    }

    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << rst[x] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
