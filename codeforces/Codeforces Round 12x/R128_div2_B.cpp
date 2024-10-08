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

int a[1005][1005];
int n, m;

bool check(int y, int x) {

    for (int i = max(1, y - 2); i <= min(n - 2, y + 2); i++) {
        for (int j = max(1, x - 2); j <= min(n - 2, x + 2); j++) {
            int c = 0;
            for (int dy = 0; dy < 3; dy++)
                for (int dx = 0; dx < 3; dx++)
                    c += a[i + dy][j + dx];
            if (c == 9) return true;

        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> y >> x;
        a[y][x] = 1;
        if (check(y, x)) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
