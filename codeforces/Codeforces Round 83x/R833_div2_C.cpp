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
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    v.pb(0);
    ll cur = 0, r = 0;

    bool flag = false;
    map<ll, int> cnt;
    for (int i = 0; i < n + 1; i++) {
        if (v[i] == 0) {
            if (flag) {
                int m = 0;
                for (auto [x, y]: cnt)m = max(y, m);
                r += m;
            } else r += cnt[0];
            cnt.clear();
            flag = true;
        }
        cur += v[i];
        cnt[cur]++;
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
