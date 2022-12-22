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
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x, y = 1;


    while (true) {
        int m = 1 << 30, mm = -(1 << 30);
        for (auto [x, y]: v) {
            m = min(m, x / y);
            mm = max(mm, x / y);
        }

        if (m * 2 > mm)break;
        int t = m * 2 - 1;
        for (auto &[x, y]: v) {
            if (t < x / y) {
                y = (x + t - 1) / t;
            }
        }
    }
    ll r = 0;
    for (auto [x, y]: v)r += y - 1;
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
