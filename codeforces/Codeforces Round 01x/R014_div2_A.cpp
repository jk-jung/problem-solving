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
    vector<string> v(n);
    for (auto &x: v)cin >> x;
    int x0 = 1 << 30, y0 = 1 << 30;
    int x1 = -1, y1 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (v[i][j] == '*') {
                x0 = min(x0, i);
                y0 = min(y0, j);
                x1 = max(x1, i);
                y1 = max(y1, j);
            }
    }
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++)
            cout << v[i][j];
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
