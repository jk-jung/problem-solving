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

bool p[1000005];

ll calc(vi &v) {
    ll r = 0;
    vector<pi> t;

    for (int x: v) {
        if (t.empty() || x == 1 || t.back().F != x)t.pb({x, 0});
        t.back().S++;
    }
    t.pb({1, 1});
    for (int i = 0; i < (int) t.size() - 1; i++) {
        if (t[i].F == 1) {
            ll s = (i == 0 || t[i - 1].F == 1) ? 0 : t[i - 1].S;
            ll e = (t[i + 1].F == 1) ? 0 : t[i + 1].S;
            r += (s + 1) * (e + 1) - 1;
        }
    }

    return r;
}

void solve() {
    int n, e;
    cin >> n >> e;
    vi v(n);
    for (int &x: v) {
        cin >> x;
        if (x == 1)x = 0;
        else if (!p[x]) x = 1;
        else x = 2;
    }

    ll r = 0;
    for (int k = 0; k < e; k++) {
        vi t;
        for (int i = k; i < n; i += e){
            if(v[i] == 2) {
                r += calc(t);
                t.clear();
            }else t.pb(v[i]);
        }
        r += calc(t);
    }
    cout << r << endl;
}

int main() {
    p[0] = p[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        if (p[i])continue;
        for (int j = i + i; j <= 1000000; j += i)p[j] = true;
    }


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
