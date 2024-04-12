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
    vector<vi> l(55);
    int t = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 20; j++) {
            if (i >> j & 1) {
                l[j].pb(i);
                t += (1 << j);
                break;
            }
        }
    }
    if (t < n) {
        cout << -1 << endl;
    } else {
        vi r;
        for (int i = 19; i >= 0; i--) {
            if (l[i].empty()) continue;
            for (int j = l[i].size() - 1; j >= 0; j--) {
                if (n < (1 << i))break;
                n -= (1 << i);
                r.pb(l[i][j]);
            }
        }
        cout << r.size() << endl;
        for (int x: r) cout << x << " ";

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
