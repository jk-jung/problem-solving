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
    vi r;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        vi v;
        for (int j = i - 1; j>=0; j--) {
            for (int k = j + 1; k <= n; k += i) {
                v.pb(k);
            }
        }
        int tt = 1 << 30;
        for (int j = 1; j < n; j++)tt = min(tt, ab(v[j] - v[j - 1]));
        if (tt > t) {
            t = tt;
            r = v;
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
