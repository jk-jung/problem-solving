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
    vector<pi> v(m);
    vi t(n + 1);
    int r = 1 << 30;
    for (auto &[x, y]: v)cin >> x >> y, r = min(r, y - x);
    for (auto [x, y]: v) {
        if (y - x == r) {
            int a = y - x + 1;
            cout << a << endl;
            for (int k = x; k <= y; k++)t[k] = k - x;
            for (int k = x - 1; k >= 1; k--)t[k] = t[k + a];
            for (int k = y + 1; k <= n; k++)t[k] = t[k - a];

            for (int i = 1; i <= n; i++)cout << t[i] << " ";
            return;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
