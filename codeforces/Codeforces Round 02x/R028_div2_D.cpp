#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


map<int, vector<vi> > V;

pair<int, vi> dp(vector<vi> v) {
    map<int, int> d;
    map<int,int> who;
    map<int, int> fr;

    for (auto x: v) {
        int i = x[0];
        int t = x[1];
        int c = x[2];
        int l = x[3];
        int r = x[4];

        if (l == 0) {
            if (d[r] < t) {
                d[r] = t;
                who[r] = i;
                fr[i] = -1;
            }
        } else {
            int before = c + r;
            if (d.count(before) && d[r] < d[before] + t) {
                d[r] = d[before] + t;
                who[r] = i;
                fr[i] = who[before];
            }
        }
    }
    vi q;
    if (d.count(0)) {
        int cur = who[0];
        q.pb(cur);
        while (cur != -1) {
            cur = fr[cur];
            if(cur == -1)break;
            q.pb(cur);
        }
    }
    return mp(d[0], q);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0, a, c, l, r; i < n; i++) {
        cin >> a >> c >> l >> r;
        vi k;
        k.pb(i + 1);
        k.pb(a);
        k.pb(c);
        k.pb(l);
        k.pb(r);
        V[c + l + r].pb(k);
    }
    int r = 0;
    vi rr;
    for (auto &[x, v]: V) {
        auto [a, b] = dp(v);
        if (a > r) {
            r = a;
            rr = b;
        }
    }
    cout << rr.size() << endl;
    reverse(rr.begin(), rr.end());
    for (int x: rr)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
