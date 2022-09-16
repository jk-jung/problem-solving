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
    int n, m;
    cin >> n >> m;

    ll r = 0;
    vi used(m);
    vector<pi> c(m);
    vector<ll> acc(m + 1);
    for (int i = 0; i < m; i++)cin >> c[i].F >> c[i].S;
    sort(c.begin(), c.end());

    acc[m] = 0;
    for (int i = m - 1; i >= 0; i--) acc[i] = acc[i + 1] + c[i].F;
    ll base = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int idx = lower_bound(c.begin(), c.end(), pi(c[i].S, -1)) - c.begin();
        if (m - idx > n) idx = m - n;
        ll rest = n - (m - idx);

        ll tmp = acc[idx];
        if(rest) {
            if(i < idx) {
                rest --;
                tmp += c[i].F;
            }
            tmp += rest * c[i].S;
        }
        r = max(r, tmp);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
