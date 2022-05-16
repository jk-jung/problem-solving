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
    int n;
    cin >> n;
    vi a(n), b(n);
    int aa = 1 << 30, bb = 1 << 30;
    for (int &x: a)cin >> x, aa = min(aa, x);
    for (int &x: b)cin >> x, bb = min(bb, x);

    ll r = 0;
    for (int i = 0; i < n; i++) {
        ll x = a[i] - aa;
        ll y = b[i] - bb;
        r += x + y - min(x, y);
    }
    cout << r << endl;
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
