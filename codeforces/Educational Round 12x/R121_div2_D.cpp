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
    vector<pi> v(n), st;
    for (auto &x: v)cin >> x.F;
    for (auto &x: v)cin >> x.S;
    for (auto &x: v) {
        st.pb(pi(x.F - x.S + 1, -1));
        st.pb(pi(x.F, 1));
    }

    sort(st.begin(), st.end());

    ll r = 0;
    int c = 0, from = st[0].F;
    for (int i = 0; i < st.size();) {
        int x = st[i].F;
        int before = c;
        while (st[i].F == x && st[i].S == -1)c--, i++;

        if(before == 0 && c < 0) from = x;
        while (st[i].F == x && st[i].S == 1)c++, i++;

        if (c == 0) {
            ll m = x - from + 1;
            r += m * (m + 1) / 2;
        }
    }
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
