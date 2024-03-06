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
    int n, t, r;
    cin >> n >> t >> r;
    vi v(n), c(1000), u(1000);
    for (int &x: v)cin >> x, x += 300;
    sort(v.begin(), v.end());

    if (t < r) {
        cout << -1;
        return;
    }
    int res = 0;
    for (int x: v) {
        for (int i = x; i >= x - t + 1; i--) {
            if (c[x] >= r) continue;
            if (u[i] == 0) {
                u[i] = 1;
                res++;
                for (int j = 0; j < t; j++)c[i + j]++;
            }
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
