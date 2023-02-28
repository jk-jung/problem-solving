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


struct iii {
    int t, b, i;

};

bool sf(iii a, iii b) {
    if (a.b == b.b) return a.t > b.t;
    return a.b < b.b;
}

bool sf2(iii a, iii b) {
    return a.t > b.t;
}

void solve() {
    int n, k, idx = 0;
    cin >> n >> k;
    vector<iii> v(n), t, org;
    vi used(n);
    for (auto &x: v) cin >> x.t >> x.b, x.i = idx++;
    org = v;
    t = v;
    sort(v.begin(), v.end(), sf);
    sort(t.begin(), t.end(), sf2);
    priority_queue<pi> q;
    ll cur = 0, r = 0;
    for (int i = 0; i < k - 1; i++) {
        cur += t[i].t, used[t[i].i] = 1;
        q.emplace(-t[i].b, t[i].i);
    }
    k--;
    int size = k, thr = k;
    for (auto &x: v) {
        if (used[x.i]) {
            cur -= x.t;
            size--;
            used[x.i] = 0;
        }
        while (!q.empty() && -q.top().F < x.b) {
            auto [b, i] = q.top();
            q.pop();
            if (used[i]) {
                used[i] = 0;
                cur -= org[i].t;
                size--;
            }
        }
        while (k < n && size < thr) {
            while (k < n && t[k].b < x.b) k++;
            if (k < n) {
                cur += t[k].t;
                q.emplace(-t[k].b, t[k].i);
                used[t[k].i] = 1;
                size++;
                k++;
            }
        }
        r = max(r, (cur + x.t) * x.b);
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
