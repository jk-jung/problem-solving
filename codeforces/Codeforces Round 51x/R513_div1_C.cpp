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

vector<pi> get(int n) {
    vi v(n);
    vector<pi> r;
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        int s = 0;
        for (int j = i; j < n; j++) {
            s += v[j];
            r.pb({s, j - i + 1});
        }
    }
    sort(r.begin(), r.end());
    return r;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pi> a = get(n);
    vector<pi> b = get(m);
    int k;
    cin >> k;
    int pos = 0, t = 0, r = 0;
    reverse(a.begin(), a.end());
    for (auto [x, y]: a) {
        int can = k / x;
        while (pos < b.size() && b[pos].F <= can)t = max(t, b[pos++].S);
        r = max(r, t * y);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
