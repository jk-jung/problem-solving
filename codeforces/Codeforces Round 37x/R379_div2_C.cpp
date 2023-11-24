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

ll n, m, k;
ll X, S;

void solve() {
    cin >> n >> m >> k >> X >> S;
    vector<pi> a(m), b(k);

    for (auto &[x, y]: a)cin >> x;
    for (auto &[x, y]: a)cin >> y;
    for (auto &[x, y]: b)cin >> y;
    for (auto &[x, y]: b)cin >> x;

    ll r = n * X;
    for (auto [x, y]: b) {
        if (x <= S)r = min(r, (n - y) * X);
    }
    for (auto [x, y]: a) {
        if (y <= S) {
            r = min(r, n * x);
            int left = S - y;
            int idx = upper_bound(b.begin(), b.end(), pi(left + 1, 0)) - b.begin();
            idx--;
            if (idx >= 0)r = min(r, (n - b[idx].S) * x);
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
