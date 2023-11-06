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

int a[55][55];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &x: v)cin >> x;

    memset(a, 31, sizeof(a));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ('0' <= v[i][j] && v[i][j] <= '9')a[i][0] = min(a[i][0], min(j, m - j));
            if ('a' <= v[i][j] && v[i][j] <= 'z')a[i][1] = min(a[i][1], min(j, m - j));
            if (v[i][j] == '#' || v[i][j] == '*' || v[i][j] == '&')a[i][2] = min(a[i][2], min(j, m - j));
        }
    }

    int r = 1 << 30;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k)continue;
                r = min(r, a[i][0] + a[j][1] + a[k][2]);
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
