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

int n;

bool can(int k, vi &v) {
    priority_queue<tuple<int, int>> q;
    queue<tuple<int, int>> used;
    for (int i = 0; i < v.size(); i++) {
        q.push(mp(v[i], i));
    }

    for (int i = 0; i < n; i++) {
        if (used.size() == k + 1) {
            q.push(used.front());
            used.pop();
        }
        if (q.empty()) return false;
        auto [x, idx] = q.top();
        q.pop();

        if (x == 0)return false;
        used.push(mp(x - 1, idx));
    }
    return true;
}

void solve() {
    cin >> n;
    vi cnt(n + 1), v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; i++)if (cnt[i])v.pb(cnt[i]);
    sort(v.begin(), v.end());

    int s = 0, e = n, r = 0;
    while (s <= e) {
        int m = (s + e) / 2;
        if (can(m, v))r = m, s = m + 1;
        else e = m - 1;
    }
    cout << r << endl;
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
