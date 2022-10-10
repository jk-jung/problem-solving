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
    int n;
    cin >> n;
    vi v(n), a(n), used(n);
    vector<pi> t;
    for (int &x: v)cin >> x;
    for (int &x: a)cin >> x;

    for (int i = 0; i < n; i++)if (!a[i])t.pb({v[i], i});
    sort(t.begin(), t.end());
    int rr = 1 << 30;
    vi rrr;
    for (int k = 0; k <= n; k++) {
        if(k == 5){
            k=k;
        }
        int idx = 0, ss = 0, s = 0, e = int(t.size()) - 1;
        vi r;
        for (int i = 0, cnt = k; i < n; i++) {
            int val;
            if (a[i]) val = v[i];
            else if (cnt) {
                val = t[s++].F;
                cnt--;
            } else {
                val = t[e--].F;
            }
            ss += val;
            r.pb(val);
            if (ss < 0)idx = i + 1;
        }

        if(idx < rr) {
            rr  =idx;
            rrr = r;
        }
    }
    for (int x: rrr)cout << x << ' ';
    cout << endl;
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
