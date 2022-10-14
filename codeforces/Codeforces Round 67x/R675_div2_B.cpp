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

int a[105][105];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];

    vi t(4);
    ll r = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < (m + 1) / 2; j++) {
            int p = n - i - 1;
            int q = m - j - 1;
            t.clear();
            t.pb(a[i][j]);
            if (i != p)t.pb(a[p][j]);
            if (i != p && j != q)t.pb(a[p][q]);
            if (j != q)t.pb(a[i][q]);

            sort(t.begin(), t.end());
            for(int x:t)r += ab(x - t[t.size() / 2]);
        }
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
