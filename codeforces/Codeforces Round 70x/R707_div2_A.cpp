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
    vi a(n), b(n), t(n);
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i];
    for (int &x: t)cin >> x;

    int r = a[0] + t[0];
    for (int i = 1; i < n; i++) {
        int m = a[i] - b[i - 1] + t[i];
        int need = (b[i - 1] - a[i - 1] + 1) / 2;
        int d_time = max(b[i - 1], r + need);

        r = d_time + m;
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
