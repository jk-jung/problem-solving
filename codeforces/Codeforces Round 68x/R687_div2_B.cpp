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
    int n, k;
    cin >> n >> k;
    map<int, vi> ck;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        ck[x].pb(i);
    }
    int r = 1 << 30;
    for (auto [_, v]: ck) {
        int y = -1, t = 0;
        v.pb(n);
        for (int x: v) {
            int dif = x - y - 1;
            int need = (dif + k - 1) / k;
            t += need;
            y += need * k;
            y = max(x, y);
        }
        r = min(r, t);
    }
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
