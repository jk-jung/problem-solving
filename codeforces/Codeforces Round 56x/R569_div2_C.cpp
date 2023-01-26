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
    int n, qq;
    cin >> n >> qq;
    vi v(n), vv;
    for (int &x: v)cin >> x;
    vector<pi> r = {{0, 0}};
    deque<int> q;
    for (int x: v)q.pb(x);
    for (int i = 1, a, b; i < n; i++) {
        a = q.front(), q.pop_front();
        b = q.front(), q.pop_front();
        r.pb({a, b});
        if (a <= b)swap(a, b);
        q.push_front(a);
        q.push_back(b);
    }
    while (qq--) {
        ll t;
        cin >> t;
        if (t < r.size()) {
            cout << r[t].F << " " << r[t].S << '\n';
        } else {
            t = (t - r.size()) % (n - 1);
            cout << q[0] << " " << q[t + 1] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
