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

bool can(ll s, vi a, vi b) {
    int n = a.size();
    int m = b.size();

    ll mm = s;
    ll bs = 0;
    ll last_mm = 0;
    int pos = 0, last = -1;
    priority_queue<pair<ll, ll>> q;
    for (int i = 0; i < n; i++) {
        s += a[i];
        mm = max(mm, s);
        if (s < 0) {
            bs += (mm - last_mm);
            for (; pos < m; pos++) {
                if (bs + b[pos] < 0)break;
                bs += b[pos];
                q.push({bs, pos});
            }
            while (!q.empty() && q.top().S <= last)q.pop();

            if (!q.empty()) {
                s += (q.top().F - mm);
                mm = max(mm, q.top().F);
                last = q.top().S;
                q.pop();
            }
            last_mm = mm;
        }
        if (s < 0)return false;
    }

    return true;
}

void solve() {
    int n, k, s;
    cin >> n >> k;
    vi a, b;
    for (int i = 0, x; i < k - 1; i++) {
        cin >> x;
        a.pb(x);
    }
    cin >> s;
    for (int i = k, x; i < n; i++) {
        cin >> x;
        b.pb(x);
    }
    reverse(a.begin(), a.end());
    cout << (can(s, a, b) || can(s, b, a) ? "YES" : "NO") << endl;
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
