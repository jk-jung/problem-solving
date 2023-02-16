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

int c[105][105];

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vi a(n), b(m);
    for (int i = 0; i < m; i++)cin >> b[i];
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            int ok = 0;
            if (x) {
                for (int k = 1; k <= h; k++) {
                    if (b[j] < k || a[i] < k)break;
                    ok = k;
                }
            }
            cout << ok << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
