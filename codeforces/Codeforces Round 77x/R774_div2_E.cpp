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

int ck[1000005];
ll d[22];

void solve() {
    int n, m;
    cin >> n >> m;

    memset(d, -1, sizeof(d));
    ll r = 1;
    for (ll i = 2; i <= n; i++) {
        if (ck[i])continue;
        int c = 0;
        for (ll k = i; k <= n; k *= i) {
            ck[k] = 1;
            c++;
        }

        if (d[c] != -1) {
            r += d[c];
            continue;
        }
        ll val = 0;

        for (int st = 1; st < (1 << c); st++) {
            int cnt = 0;
            ll lcm = 0;
            ll s = -(1 << 30);
            ll e = -s;
            for (ll k = 0; k < c; k++) {
                if (st >> k & 1) {
                    cnt++;
                    if (lcm == 0)lcm = k + 1;
                    else lcm = lcm * (k + 1) / gcd(lcm, (k + 1));
                    s = max(s, k + 1);
                    e = min(e, (k + 1) * m);
                }
            }
            ll t = e / lcm - (s - 1) / lcm;
            if (cnt % 2)val += t;
            else val -= t;
        }
        d[c] = val;
        r += val;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
