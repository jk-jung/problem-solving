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
    vi v(n);
    for (int &x: v)cin >> x;

    int M = 0;
    vector<pi> q;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        while (!q.empty() && q.back().S <= y)q.pop_back();
        q.emplace_back(x, y);
        M = max(M, y);
    }
    q.emplace_back(0, 0);

    deque<int> t = deque<int>(v.begin(), v.begin() + M), r;
    sort(t.begin(), t.end());
    for (int i = 1; i < q.size(); i++) {
        int cnt = q[i - 1].S - q[i].S;
        int direction = q[i - 1].F;
        while (cnt--) {
            if (direction == 1) {
                r.push_front(t.back());
                t.pop_back();
            } else {
                r.push_front(t.front());
                t.pop_front();
            }
        }
    }
    for (auto x: r)cout << x << " ";
    for (int i = M; i < n; i++)cout << v[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
