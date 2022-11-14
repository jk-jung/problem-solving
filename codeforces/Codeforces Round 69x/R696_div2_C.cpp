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

int cnt[1000005];
int n;

void go(int x, int i, vi &v, vector<pi> &r) {
    if (r.size() * 2 == n)return;

    int a = -1;
    for (; i < v.size(); i++)
        if (cnt[v[i]]) {
            a = v[i];
            break;
        }
    cnt[a]--;
    int b = x - a;
    if (!cnt[b]) {
        cnt[a]++;
        r.clear();
        return;
    }
    cnt[b]--;
    r.pb({a, b});
    go(a, i, v, r);
    cnt[a]++;
    cnt[b]++;
}

void solve() {
    cin >> n;
    n *= 2;
    vi v(n);
    for (int &x: v)cin >> x, cnt[x]++;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    bool no = true;
    cnt[v[0]]--;
    for (int i = 1; i < n; i++) {
        vector<pi> r = {pi{v[0], v[i]}};
        cnt[v[i]]--;
        go(v[0], 1, v, r);
        cnt[v[i]]++;
        if (!r.empty()) {
            cout << "YES\n" << v[0] + v[i] << endl;
            for (auto [x, y]: r) {
                cout << x << " " << y << endl;
            }
            no = false;
            break;
        }
    }
    if (no) cout << "NO\n";
    for (int x: v)cnt[x] = 0;
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
