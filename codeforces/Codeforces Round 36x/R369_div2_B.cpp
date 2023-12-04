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

ll n;
ll a[505][505];

map<ll, int> check() {
    map<ll, int> r;
    for (int i = 0; i < n; i++) {
        ll s1 = 0, s2 = 0, s3 = 0, s4 = 0;
        for (int j = 0; j < n; j++) {
            s1 += a[i][j];
            if (a[i][j] == 0)s1 += 1ll << 55;
            s2 += a[j][i];
            if (a[j][i] == 0)s2 += 1ll << 55;
            s3 += a[j][j];
            if (a[j][j] == 0)s3 += 1ll << 55;
            s4 += a[j][n - j - 1];
            if (a[j][n - j - 1] == 0)s4 += 1ll << 55;
        }
        if (s1 < (1ll << 55))r[s1]++;
        if (s2 < (1ll << 55))r[s2]++;
        if (s3 < (1ll << 55))r[s3]++;
        if (s4 < (1ll << 55))r[s4]++;
    }
    return r;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)cin >> a[i][j];
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    map<ll, int> t = check();
    ll tt = 0, cnt = -1;
    for (auto [x, y]: t) {
        if (y > cnt) {
            cnt = y;
            tt = x;
        }
    }
    ll r = 0;
    for (int i = 0; i < n; i++) {
        ll s = 0;
        for (int j = 0; j < n; j++)s += a[i][j];
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                a[i][j] = tt - s;
                r = a[i][j];
                break;
            }
        }
    }
    if (r <= 0)r = -1;
    cout << (check().size() == 1 ? r : -1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
