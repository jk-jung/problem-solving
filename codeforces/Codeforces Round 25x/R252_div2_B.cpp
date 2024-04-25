#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x >> y;
    sort(v.begin(), v.end());
    int r = 0;
    for (int i = 1; i <= 3001; i++) {
        int t = m;
        for (auto &[x, y]: v) {
            if (x == i - 1) {
                int cnt = min(t, y);
                r += cnt;
                y -= cnt;
                t -= cnt;
            }
        }
        for (auto &[x, y]: v) {
            if (x == i) {
                int cnt = min(t, y);
                r += cnt;
                y -= cnt;
                t -= cnt;
            }
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
