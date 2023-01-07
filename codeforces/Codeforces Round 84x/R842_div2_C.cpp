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
    int n;
    cin >> n;
    vector<pi> v(n);
    vi a(n), b(n), aa(n + 1), bb(n + 1);
    for (int i = 0; i < n; i++)cin >> v[i].F, v[i].S = i, aa[i + 1] = bb[i + 1] = 1;
    sort(v.begin(), v.end());
    for (int i = n - 1; i >= 0; i--) {
        auto [x, idx] = v[i];
        if (aa[x]) a[idx] = x, aa[x]--;
        else if (bb[x]) b[idx] = x, bb[x]--;
        else {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0, ai = 1, bi = 1; i < n; i++) {
        auto [x, idx] = v[i];
        while (ai <= n && aa[ai] == 0)ai++;
        while (bi <= n && bb[bi] == 0)bi++;
        if (min(ai, bi) > x) {
            cout << "NO\n";
            return;
        }
        if (ai <= bi && a[idx] == 0)a[idx] = ai, aa[ai]--;
        else b[idx] = bi, bb[bi]--;
    }
    cout << "YES\n";
    for (int x: a)cout << x << " ";
    cout << endl;
    for (int x: b)cout << x << " ";
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
