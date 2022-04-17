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
    int n;
    ll m;
    cin >> n >> m;
    vi v(n);
    vector<ll> v1, v2;
    for (int &x: v)cin >> x;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x == 1)v1.pb(v[i]);
        else v2.pb(v[i]);
    }
    sort(v1.begin(), v1.end()), reverse(v1.begin(), v1.end());
    sort(v2.begin(), v2.end()), reverse(v2.begin(), v2.end());

    for (int i = 1; i < v1.size(); i++)v1[i] += v1[i - 1];
    for (int i = 1; i < v2.size(); i++)v2[i] += v2[i - 1];

    int r = 1 << 30;
    for (int i = 0; i <= v1.size(); i++) {
        ll need = m;
        int cur = i;
        if (i)need -= v1[i - 1];

        if (need <= 0) {
            r = min(r, cur);
            break;
        }
        int x = lower_bound(v2.begin(), v2.end(), need) - v2.begin();
        if (x == v2.size())continue;

        r = min(r, cur + (x + 1) * 2);
    }

    if (r == (1 << 30))r = -1;
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
