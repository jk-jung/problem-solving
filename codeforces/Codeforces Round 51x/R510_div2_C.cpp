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
    int n, c = 0;
    cin >> n;
    vector<pi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].F, v[i].S = i + 1;
        if (v[i].F < 0)c++;
    }
    vi rm;
    sort(v.begin(), v.end());
    if (c % 2) {
        int last = 0;
        for (auto [x, y]: v) {
            if (x >= 0) {
                rm.pb(last);
                break;
            }
            last = y;
        }
        if (rm.empty())rm.pb(last);
    }

    for (auto [x, y]: v)if (x == 0)rm.pb(y);

    set<int> idx;
    for (int i = 1; i <= n; i++)idx.insert(i);
    if (!rm.empty()) {
        for (int i = 1; i < rm.size(); i++)cout << "1 " << rm[i - 1] << " " << rm[i] << endl;
        if (rm.size() != n) cout << "2 " << rm.back() << endl;
        for (int x: rm)idx.erase(x);
    }
    if (idx.size() >= 2) {
        int m = idx.size();
        for (int i = 1; i < m; i++) {
            auto it = idx.begin();
            int a = *it;
            int b = *(++it);
            idx.erase(a);
            cout << "1 " << a << " " << b << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
