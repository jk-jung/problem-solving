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
int n;

bool can(vi &a, vi &b, int x) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] < r)continue;
        if (a[i] < x - r - 1)continue;
        r++;
        if (r == x)return true;
    }
    return false;
}

void solve() {

    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i];

    int s = 1, e = n, r = 1;
    while (s <= e) {
        int m = (s + e) / 2;

        if (can(a, b, m))s = m + 1, r = m;
        else e = m - 1;
    }
    cout << r << '\n';
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
