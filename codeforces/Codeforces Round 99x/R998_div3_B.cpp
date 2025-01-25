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
    vector<vi> v(n);
    for (int i = 0; i < n; i++) {
        vi t(m);
        for (int &x: t)cin >> x;
        sort(t.begin(), t.end());
        t.pb(100000 + i);
        v[i] = t;
    }
    sort(v.begin(), v.end());
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            int idx = j * n + i;
            if (v[i][j] != idx) {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (int i = 0; i < n; i++)cout << v[i][m] - 99999 << " ";
    cout << endl;

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
