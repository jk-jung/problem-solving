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
    int n, m = 0;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x, m += (x < 0 ? 1 : 0);
    vi t = v;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        t[i] = ab(t[i]);
        if (i < m)t[i] *= -1;
        if(i && t[i - 1] > t[i])ok = false;
    }

    cout << (ok ? "YES\n" : "NO\n");
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
