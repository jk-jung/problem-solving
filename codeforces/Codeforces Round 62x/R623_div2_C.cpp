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
    vi v(n), r(2 * n), used(2 * n + 1);
    for (int &x: v)cin >> x;
    for (int i = 0; i < 2 * n; i += 2) {
        r[i] = v[i / 2];
        used[r[i]] = 1;
    }

    for (int i = 1; i < 2 * n; i += 2) {
        int t = r[i - 1];
        for (int k = 1; k <= 2 * n; k++)
            if (used[k] == 0 && k > t) {
                r[i] = k;
                used[k] = 1;
                break;
            }
        if (!r[i]) {
            cout << -1 << endl;
            return;
        }
    }
    for (int x: r)cout << x << " ";
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
