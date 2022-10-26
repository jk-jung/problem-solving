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
    vi v(6);
    for (int &x: v)cin >> x;
    int n;
    cin >> n;
    vi a(n), idx(n);
    for (int &x: a)cin >> x;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < 6; i++)v[i] = v.back() - v[i];
    sort(v.begin(), v.end());
    sort(a.begin(), a.end());

    v.pb(v[5]);
    v.pb(v[5]);
    v.pb(v[5]);

    priority_queue<tuple<int, int, int>> q;
    for (int i = 0; i < a.size(); i++) q.push({-a[i], -v[1], i});
    int e = a.back(), s = a[0];
    int r = e - s;
    while (true) {
        auto [x, y, z] = q.top();
        q.pop();
        int nxt = -x - y, i = ++idx[z];
        e = max(e, nxt);

        q.push({-nxt, v[i] - v[i + 1], z});
        r = min(r, e + get<0>(q.top()));
        if (i == 6)break;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
