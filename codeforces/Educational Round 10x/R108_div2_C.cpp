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
    cin >> n;
    vi v(n), u(n);

    map<int, vector<ll>> ck, ss;

    for (int &x: u)cin >> x;
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++)ck[u[i]].pb(v[i]);
    for (auto &[_, vv]: ck) {
        sort(vv.begin(), vv.end());
        reverse(vv.begin(), vv.end());

        int m = vv.size();
        if (!ss.count(m))ss[m] = vector<ll>(m);
        vector<ll> &q = ss[m];
        ll s = 0;
        for (int i = 0; i < m; i++) {
            q[i] += vv[i] + s;
            s += vv[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        ll r = 0;
        for (auto &[c, vv]: ss) {
            int l = c - c % i - 1;
            if(l >= 0)r += vv[l];
        }
        cout << r << " ";
    }
    cout << endl;
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
