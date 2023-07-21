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
    vector<string> v(n);
    vector<vi> c(n, vi(n));
    int r = 0;
    for (auto &x: v)cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool ok1 = j + k <= n;
            bool ok2 = i + k <= n;
            for (int a = 0; a < k; a++) {
                if (ok1 && v[i][j + a] == '#')ok1 = false;
                if (ok2 && v[i + a][j] == '#')ok2 = false;
            }
            for (int a = 0; a < k; a++) {
                if (ok1) r = max(r, ++c[i][j + a]);
                if (ok2) r = max(r, ++c[i + a][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] == r) {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
