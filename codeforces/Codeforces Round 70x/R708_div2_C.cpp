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
    int n, k;
    cin >> n >> k;

    vi r;
    while (k > 3) {
        k--;
        n--;
        r.pb(1);
    }
    int base = 1, c = 0;
    while (n % 2 == 0) {
        n /= 2;
        base *= 2;
        c++;
    }
    if (n == 1) {
        r.pb(base / 4);
        r.pb(base / 4);
        r.pb(base / 2);
    } else {
        r.pb(base);
        r.pb((n / 2) * base);
        r.pb((n / 2) * base);
    }
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
