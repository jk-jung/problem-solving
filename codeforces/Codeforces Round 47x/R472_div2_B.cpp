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
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    vi c(m);
    for (int i = 0; i < n; i++) {
        vi t;
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '#') {
                if (c[j]) {
                    cout << "No";
                    return;
                }
                c[j] = 1;
                t.pb(j);
            }
        }
        for (int y = i; y < n; y++) {
            vi tt;
            for (int j = 0; j < m; j++)
                if (v[y][j] == '#') {
                    tt.pb(j);
                }
            if (tt == t) {
                for (int x: tt)v[y][x] = '.';
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
