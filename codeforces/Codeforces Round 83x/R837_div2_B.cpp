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
    ll n, m;
    cin >> n >> m;
    vector<pi> v(m);
    for (auto &[x, y]: v) {
        cin >> x >> y;
        if (x > y)swap(x, y);
    }
    sort(v.begin(), v.end());

    ll r = 0;
    map<int, int> ck;
    for (auto [x, y]: v)ck[y]++;
    for (int i = 1, pos = 0; i <= n; i++) {
        if (ck.empty())r += n - i + 1;
        else r += ck.begin()->F - i;
        while (pos < m && v[pos].F == i) {
            int t = v[pos++].S;
            if (--ck[t] == 0)ck.erase(t);
        }
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
