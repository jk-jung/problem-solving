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
    for (auto &[x, y]: v)cin >> x >> y;
    int r = 1 << 30;
    for (auto [x, y]: v) {
        int nt = -1;
        if (x <= r)nt = max(nt, x);
        if (y <= r)nt = max(nt, y);
        if (nt == -1) {
            cout << "NO\n";
            return;
        }
        r = nt;
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
