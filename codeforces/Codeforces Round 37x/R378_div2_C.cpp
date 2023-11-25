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

vector<pi> process(vi &v) {
    for (int i = 0; i < v.size(); i++) {
        vector<pi> t;
        int s = i - 1, e = i + 1, cur = v[i];
        while (true) {
            bool ok = false;
            if (s >= 0 && v[s] < cur) {
                t.pb({s + 1, 0});
                cur += v[s--];
                ok = true;
            }
            if (e < v.size() && v[e] < cur) {
                t.pb({s + 1, 1});
                cur += v[e++];
                ok = true;
            }
            if (s == -1 && e == v.size())return t;
            if (!ok)break;
        }
    }
    return {{-1, -1}};
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    int m;
    cin >> m;
    vi t(m);
    for (int &x: t)cin >> x;

    vector<pi> r;
    int i = 0, cnt = 0;
    for (int x: t) {
        vi tt;
        while (i < v.size() && x > 0) {
            x -= v[i];
            tt.pb(v[i++]);
        }
        if (x != 0) {
            cout << "NO\n";
            return;
        }
        vector<pi> rr = process(tt);
        if (rr.size() == 1 && rr[0].F == -1) {
            cout << "NO\n";
            return;
        }
        cnt++;
        for (auto [a, b]: rr) r.pb(pi(a + cnt, b));
    }
    if(i != v.size()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (auto [x, y]: r) {
        cout << x << " " << (y ? "R" : "L") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
