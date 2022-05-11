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
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;
    for (int x: v)cin >> x;

    sort(v.begin(), v.end());
    queue<int> q;
    vector<pi> seg;
    int r = 0;
    for (int x: v) {
        while (!q.empty() && q.front() < x - k)q.pop();
        q.push(x);
        if (!seg.empty() && seg.back().F == x) {
            seg.back().S = q.size();
        } else {
            seg.pb({x, q.size()});
        }
        r = max(r, (int) q.size());
    }

    vi ss(seg.size() + 1);
    for (int i = (int) seg.size() - 1; i >= 0; i--) {
        ss[i] = max(ss[i + 1], seg[i].S);
    }

    for (auto [x, cnt]: seg) {
        int idx = lower_bound(seg.begin(), seg.end(), mp(x + k + 1, 0)) - seg.begin();
        if (idx < seg.size()) {
            r = max(r, cnt + ss[idx]);
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
