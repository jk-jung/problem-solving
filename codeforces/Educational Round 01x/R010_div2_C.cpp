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
    vi v(n), p(n + 1);
    vector<pi> t(m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        p[v[i]] = i;
    }
    map<int, int> ck;
    for (auto &[x, y]: t) {
        cin >> x >> y, x = p[x], y = p[y];
        if (x > y) swap(x, y);
        ck[y]++;
    }
    sort(t.begin(), t.end());

    ll r = 0;
    for (int i = 0, j = 0; i < n; i++) {
        int y = ck.empty() ? n : ck.begin()->F;
        r += y - i;
        while (j < m && t[j].F == i) {
            int x = t[j++].S;
            if (--ck[x] == 0) ck.erase(x);
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
