#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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

int a[1000];

void solve() {
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i], s += a[i];

    bool ok = true;

    for (int i = 2; i < s; i++) {
        if (s % i == 0)ok = false;
    }

    vi r;
    if (!ok) {
        for (int i = 1; i <= n; i++)r.pb(i);
    } else {
        for (int k = 1; k <= n; k++) {
            if (a[k] % 2 == 1) {
                for (int i = 1; i <= n; i++)if (k != i)r.pb(i);
                break;
            }
        }
    }
    cout << r.size() << "\n";
    for (int x: r)cout << x << " ";
    cout << '\n';
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
