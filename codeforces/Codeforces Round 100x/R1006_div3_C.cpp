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
    int n, x;
    cin >> n >> x;
    vi r;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if ((x & i) == i) {
            if (i == n - 1) {
                if ((cur | i) == x)r.pb(i);
                else r.pb(x);
            } else r.pb(i);
            cur |= i;
        }else {
            r.pb(x);
        }
    }

    for (int y: r)cout << y << " ";
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
