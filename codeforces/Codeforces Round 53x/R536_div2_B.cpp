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
    int n, m;
    cin >> n >> m;
    vi a(n), c(n), t(m), d(m);
    for (int &x: a)cin >> x;
    for (int &x: c)cin >> x;
    for (int i = 0; i < m; i++)cin >> t[i] >> d[i], t[i]--;
    set<pi> ck;
    for (int i = 0; i < n; i++)ck.insert(mp(c[i], i));

    for (int i = 0; i < m; i++) {
        ll idx = t[i], cnt = d[i];
        ll tt = min(cnt, (ll) a[idx]);
        ll tmp = 0;
        a[idx] -= tt;
        cnt -= tt;
        tmp += tt * c[idx];
        while (cnt > 0 && !ck.empty()) {
            pi x = *ck.begin();
            idx = x.S;
            tt = min(cnt, (ll) a[idx]);
            a[idx] -= tt;
            tmp += tt * c[idx];
            cnt -= tt;
            if (a[idx] == 0)ck.erase(x);
        }
        if (cnt == 0)
            cout << tmp << endl;
        else
            cout << 0 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
