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
    int n, w;
    cin >> n >> w;
    vi v(n), r(n);
    for (int &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        int t = (v[i] + 1) / 2;
        w -= t;
        r[i] = t;
    }
    if (w < 0) {
        cout << -1 << endl;
        return;
    }
    while (w) {
        for (int k = 100; k >= 1; k--) {
            for (int i = 0; i < n; i++)if (w > 0 && v[i] == k && r[i] < k)r[i]++, w--;
        }
    }
    for (int x: r)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
