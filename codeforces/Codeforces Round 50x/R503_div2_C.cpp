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

    map<int, vector<pi>> ck;
    vector<pi> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1)b = 1 << 30;
        v.pb({b, i});
        ck[a].pb({b, i});
    }
    for (auto &[x, y]: ck)sort(y.begin(), y.end());
    sort(v.begin(), v.end());
    ll r = 1ll << 60;
    for (int i = 0; i <= n; i++) {
        int cnt = 0;
        ll cost = 0;
        vi used(n);
        for (auto &[x, y]: ck) {
            if (x == 1)cnt += y.size();
            else if (y.size() > i) {
                for (int j = 0; j < y.size() - i; j++)cost += y[j].F, used[y[j].S] = 1, cnt++;
            }
        }
        for (int j = 0; j < n && cnt <= i; j++) {
            if (!used[v[j].S]) {
                cost += v[j].F;
                cnt++;
            }
        }
        if (cnt > i)
            r = min(r, cost);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
