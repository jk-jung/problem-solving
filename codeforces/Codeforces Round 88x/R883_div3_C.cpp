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
typedef pair<ll, ll> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

void solve() {
    ll n, m, h;
    cin >> n >> m >> h;

    pi t;
    ll r = 1;
    for (int i = 0; i < n; i++) {
        vi v(m);
        for (int &x: v)cin >> x;
        sort(v.begin(), v.end());
        pi b;
        ll now = 0;

        for (int x: v) {
            if (now + x <= h) {
                now += x;
                b.F += 1;
                b.S -= now;
            }
        }
        if (i == 0)t = b;
        else if (b > t) {
            r++;
        }
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
