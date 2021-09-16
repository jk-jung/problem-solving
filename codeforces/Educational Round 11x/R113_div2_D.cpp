#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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


ll calc(vi &x, vector<pi> &v) {
    ll r = 0;
    sort(v.begin(), v.end());
    for (int i = 1, pos = 0; i < x.size(); i++) {
        map<int, int> ck;
        for (; pos < v.size(); pos++) {
            int x2 = v[pos].F;
            if (x2 >= x[i])break;
            if (x[i - 1] < x2) ck[v[pos].S]++;
        }
        ll s = 0;
        for (auto it: ck) {
            r += it.S * s;
            s += it.S;
        }
    }
    return r;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vi x(n), y(m);
    vector<pi> v(k);

    for (int i = 0; i < n; i++)cin >> x[i];
    for (int i = 0; i < m; i++)cin >> y[i];
    for (int i = 0; i < k; i++)cin >> v[i].F >> v[i].S;

    ll r = calc(x, v);
    for (int i = 0; i < k; i++) swap(v[i].F, v[i].S);
    r += calc(y, v);

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
