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

int a[105][105];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t = a[i][j];
            vi v;
            if (i - 1 >= 0)v.pb(a[i - 1][j]);
            if (i + 1 < n)v.pb(a[i + 1][j]);
            if (j - 1 >= 0)v.pb(a[i][j - 1]);
            if (j + 1 < m)v.pb(a[i][j + 1]);
            sort(v.begin(), v.end());
            if (!v.empty() && v.back() < t) {
                a[i][j] = v.back();
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
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
