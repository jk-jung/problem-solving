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
    ll n, m;
    cin >> n;
    m = n;
    if (n % 2) {
        cout << 2 << '\n';
        return;
    }

    ll cc = 2;
    while (n % 2 == 0) {
        n /= 2;
        cc *= 2;
    }

    if (cc < m * 2 / (cc - 1)) {
        cout << cc << '\n';
        return;
    }
    if (n > 1) {
        if (n < m * 2 / (n - 1))
            cout << n << '\n';
        else {

            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    cout << i << '\n';
                    return;
                }
            }

            cout << -1 << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
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
