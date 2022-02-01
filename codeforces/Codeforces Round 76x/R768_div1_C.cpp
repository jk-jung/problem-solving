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

int n;

void solve() {
    cin >> n;
    vi s(n + 1, 1 << 30), e(n + 1, -1);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s[x] = min(s[x], i);
        e[x] = max(e[x], i);
    }
    vector<pi> v, t;
    for (int i = 1; i <= n; i++) {
        if (e[i] == -1 || s[i] == e[i]) continue;
        v.pb({s[i], e[i]});
    }
    sort(v.begin(), v.end());

    int right_most = -1;
    for (auto x: v) {
        if (x.S > right_most) {
            if(t.size() >= 2 && x.F < t[t.size() - 2].S)
                t.pop_back();
            t.pb(x);
            right_most = x.S;
        }
    }

    int r = 0;
    for (int i = 0, start = 0; i < t.size(); i++) {
        if (i + 1 == t.size() || t[i].S < t[i + 1].F) {
            int m = t[i].S - t[start].F + 1;
            int cnt = i - start + 1;
            r += m - cnt - 1;
            start = i + 1;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
