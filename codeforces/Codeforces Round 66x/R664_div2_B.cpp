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
    int n, m, x, y;
    cin >> n >> m >> y >> x;

    cout << y << " " << x << endl;
    for (int j = m; j >= 1; j--) {
        if (j == x)continue;
        cout << y << " " << j << endl;
    }
    for (int i = 1, st = 0; i <= n; i++) {
        if (i == y)continue;
        st ^= 1;
        for (int j = 1; j <= m; j++) {
            if (y == i && j == x)continue;
            if (y == i && j == 1)continue;

            cout << i <<" " << (st ? j : (m - j + 1)) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
