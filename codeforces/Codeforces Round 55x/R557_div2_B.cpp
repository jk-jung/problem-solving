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
int b[55][55];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> b[i][j];

    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) if (a[i][j] > b[i][j])swap(a[i][j], b[i][j]);

    bool ok = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i) {
                if (a[i][j] <= a[i - 1][j] || b[i][j] <= b[i - 1][j])
                    ok = false;
            }
            if (j) {
                if (a[i][j] <= a[i][j - 1] || b[i][j] <= b[i][j - 1])
                    ok = false;
            }
        }
    }
    cout << (ok ? "Possible" : "Impossible") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
