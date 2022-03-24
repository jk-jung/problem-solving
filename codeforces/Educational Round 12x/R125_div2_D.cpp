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

void solve() {
    int n, C;
    map<int, ll> ck;
    cin >> n >> C;
    for (int i = 0, c, d, h; i < n; i++) {
        cin >> c >> d >> h;
        ck[c] = max(ck[c], (ll) d * h);
    }
    vector<ll> v(C + 1);

    for (auto[k, x]: ck) {
        for (int i = k, t = 1; i <= C; i += k, t++)
            v[i] = max(v[i], x * t);
    }
    for (int i = 1; i <= C; i++)v[i] = max(v[i], v[i - 1]);

    int m;
    cin >> m;
    while (m--) {
        ll D, H;
        cin >> D >> H;
        ll x = (ll) D * H + 1;
        int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
        if (idx == C + 1) idx = -1;
        cout << idx << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
