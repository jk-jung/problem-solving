#include <string.h>
#include <stdio.h>
#include <math.h>
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
    int n, l, r, s, m = 0, M = 0;
    cin >> n >> l >> r >> s;
    for (int i = 0; i <= r - l; i++) {
        m += i + 1;
        M += n - i;
    }
    if (!(m <= s && s <= M)) {
        cout << -1 << endl;
        return;
    }
    vi v, u(501);
    for (int i = n; i >= 1; i--) {
        int t = r - l + 1 - v.size();
        if (t == 0)break;

        int a = t * (t - 1) / 2;
        if (a + i <= s) {
            s -= i;
            v.pb(i);
            u[i] = 1;
        }
    }

    for (int i = 1, pos = 1; i <= n; i++) {
        if (l <= i && i <= r) {
            cout << v[i - l] <<" ";
        } else {
            while (u[pos])pos++;
            cout << pos ++  << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
