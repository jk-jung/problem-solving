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

vi d;
int n;

int go(int x, vector<pi> &r) {
    if (x >= n) return 1;
    if (d[x] != -1) return d[x];
    d[x] = 0;
    for (int i = 0; i * i <= (n - 1) * 2; i++) {
        int y = i * i - x;
        if (y >= n) break;
        if (y >= x) {
            r.pb({x, y});
            if (go(y + 1, r)) return d[x] = 1;
            r.pop_back();
        }
    }
    return d[x] = 0;
}

void solve() {
    cin >> n;
    d.clear();
    d.resize(n, -1);
    vector<pi> r;
    int t = go(0, r);

    if (t) {
        for (auto [x, y]: r) {
            for (int i = y; i >= x; i--)cout << i << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

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
